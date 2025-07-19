// Made by LSH

#include "GAS/GameplayAbility/Attack/GA_Attack.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"
#include "Character/Character/BFCharacter.h"
#include "Player/State/BFPlayerState.h"
#include "Abilities/Tasks/AbilityTask_PlayMontageAndWait.h"

UGA_Attack::UGA_Attack()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(BFGameplayTags::State::Attack);

	ActivationBlockedTags.AddTag(BFGameplayTags::State::Jump);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Attack);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Blocked);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Hitted);
	ActivationBlockedTags.AddTag(BFGameplayTags::State::Die);
}

bool UGA_Attack::CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags, const FGameplayTagContainer* TargetTags, OUT FGameplayTagContainer* OptionalRelevantTags) const
{
	if (!Super::CanActivateAbility(Handle, ActorInfo, SourceTags, TargetTags, OptionalRelevantTags))
	{
		return false;
	}

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	if (ASC->GetOwner()->IsA(ABFPlayerState::StaticClass()))
	{
		int8 Combo = Cast<UBFPlayerAttributeSet>(ASC->GetAttributeSet(UBFPlayerAttributeSet::StaticClass()))->GetCurrentCombo();

		if (Combo > 1 && !ASC->HasMatchingGameplayTag(BFGameplayTags::Attack::CanCombo))
		{
			return false;
		}
	}
	
	return true;
}

void UGA_Attack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Attack);
	ASC->RemoveLooseGameplayTag(BFGameplayTags::Attack::CanCombo);
	ASC->ApplyGameplayEffect(Cast<ABFCharacter>(ActorInfo->AvatarActor.Get()), ComboIncreaseEffectClass);
	ASC->PlayMontage(this, ActivationInfo, AttackMontage, 1.f);

	UAbilityTask_PlayMontageAndWait* Task = UAbilityTask_PlayMontageAndWait::CreatePlayMontageAndWaitProxy(this, FName("MontageWait"), AttackMontage);
	Task->OnCompleted.AddDynamic(this, &ThisClass::ResetAttackCombo);
	Task->ReadyForActivation();
}

void UGA_Attack::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Attack);

	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);
}

void UGA_Attack::ResetAttackCombo()
{
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());

	ASC->ApplyGameplayEffect(Cast<ABFCharacter>(GetAvatarActorFromActorInfo()), ComboResetEffectClass);
	ASC->RemoveLooseGameplayTag(BFGameplayTags::Attack::CanCombo);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Attack);
}