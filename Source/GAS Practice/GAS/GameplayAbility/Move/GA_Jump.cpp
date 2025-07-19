// Made by LSH

#include "GAS/GameplayAbility/Move/GA_Jump.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/AbilityTask/Jump/AT_Landed.h"
#include "Character/Character/BFCharacter.h"

UGA_Jump::UGA_Jump()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(BFGameplayTags::State::Jump);

	ActivationBlockedTags.AddTag(BFGameplayTags::State::Jump);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Attack);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Blocked);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Hitted);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Die);
}

void UGA_Jump::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ABFCharacter* Character = Cast<ABFCharacter>(ActorInfo->AvatarActor.Get());
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Jump);
	Character->Jump();

	UAT_Landed* Task = UAT_Landed::CreateTask(this);
	Task->ReadyForActivation();
}

void UGA_Jump::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());

	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Jump);

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}