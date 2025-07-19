// Made by LSH

#include "GAS/GameplayAbility/Hit/GA_Damaged.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "Character/Character/BFCharacter.h"

UGA_Damaged::UGA_Damaged()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(BFGameplayTags::State::Hitted);

	ActivationBlockedTags.AddTag(BFGameplayTags::State::Hitted);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Blocked);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Die);
}

void UGA_Damaged::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ABFCharacter* Character = Cast<ABFCharacter>(ActorInfo->AvatarActor.Get());

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Hitted);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Attack);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Jump);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Run);

	FTimerHandle EndHandle;
	GetWorld()->GetTimerManager().SetTimer(EndHandle, [this, Handle, ActorInfo, ActivationInfo]() {EndAbility(Handle, ActorInfo, ActivationInfo, false, false); }, 1.0f, false);
}

void UGA_Damaged::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Hitted);

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}