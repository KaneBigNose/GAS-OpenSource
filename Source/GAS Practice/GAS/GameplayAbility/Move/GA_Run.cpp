// Made by LSH

#include "GAS/GameplayAbility/Move/GA_Run.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "Character/Character/BFCharacter.h"

UGA_Run::UGA_Run()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(BFGameplayTags::State::Run);

	ActivationBlockedTags.AddTag(BFGameplayTags::State::Jump);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Run);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Attack);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Blocked);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Hitted);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Die);
}

void UGA_Run::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());

	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Run);
	ASC->ApplyGameplayEffect(Cast<ABFCharacter>(ActorInfo->AvatarActor.Get()), SpeedChangeEffectClass, BFGameplayTags::Data::Speed, 2.0f);
}

void UGA_Run::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Run);
	ASC->ApplyGameplayEffect(Cast<ABFCharacter>(ActorInfo->AvatarActor.Get()), SpeedChangeEffectClass, BFGameplayTags::Data::Speed, 0.5f);

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}