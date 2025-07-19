// Made by LSH

#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/GameplayEffect/EffectContext/BFEffectContext.h"
#include "Character/Character/BFCharacter.h"

FGameplayEffectContextHandle UBFAbilitySystemComponent::MakeEffectContext() const
{
	FBFEffectContext* NewContext = new FBFEffectContext();
	FGameplayEffectContextHandle Handle = FGameplayEffectContextHandle(NewContext);
	Handle.AddInstigator(GetOwner(), GetAvatarActor());
	return Handle;
}

void UBFAbilitySystemComponent::ActiveAbilitiesByTag(FGameplayTag ActiveTag)
{
	FGameplayTagContainer ActivateTag;
	ActivateTag.AddTag(ActiveTag);

	TryActivateAbilitiesByTag(ActivateTag);
}

void UBFAbilitySystemComponent::CancelAbilitiesByTag(FGameplayTag CancelTag)
{
	FGameplayTagContainer CancelTags;
	CancelTags.AddTag(CancelTag);

	CancelAbilities(&CancelTags);
}

FActiveGameplayEffectHandle UBFAbilitySystemComponent::ApplyGameplayEffect(ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass)
{
	FGameplayEffectContextHandle ContextHandle = MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(ApplyEffectClass, 1.0f, ContextHandle);
	UBFAbilitySystemComponent* TargetASC = Cast<UBFAbilitySystemComponent>(Target->GetAbilitySystemComponent());

	return ApplyGameplayEffectSpecToTarget(*SpecHandle.Data, TargetASC);
}

FActiveGameplayEffectHandle UBFAbilitySystemComponent::ApplyGameplayEffect(ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass, FGameplayTag DataTag, float EffectValue)
{
	FGameplayEffectContextHandle ContextHandle = MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(ApplyEffectClass, 1.0f, ContextHandle);
	UBFAbilitySystemComponent* TargetASC = Cast<UBFAbilitySystemComponent>(Target->GetAbilitySystemComponent());

	SpecHandle.Data->SetSetByCallerMagnitude(DataTag, EffectValue);

	return ApplyGameplayEffectSpecToTarget(*SpecHandle.Data, TargetASC);
}

FActiveGameplayEffectHandle UBFAbilitySystemComponent::ApplyGameplayEffect(ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass, float ValueScale)
{
	FGameplayEffectContextHandle ContextHandle = MakeEffectContext();
	FBFEffectContext* BFContext = static_cast<FBFEffectContext*>(ContextHandle.Get());
	BFContext->ValueScale = ValueScale;

	FGameplayEffectSpecHandle SpecHandle = MakeOutgoingSpec(ApplyEffectClass, 1.0f, ContextHandle);
	UBFAbilitySystemComponent* TargetASC = Cast<UBFAbilitySystemComponent>(Target->GetAbilitySystemComponent());

	return ApplyGameplayEffectSpecToTarget(*SpecHandle.Data, TargetASC);
}

bool UBFAbilitySystemComponent::AddUniqueGameplayTag(FGameplayTag TargetTag)
{
	if (!HasMatchingGameplayTag(TargetTag))
	{
		AddLooseGameplayTag(TargetTag);
		return true;
	}
	return false;
}

bool UBFAbilitySystemComponent::AddUniqueGameplayTags(FGameplayTagContainer TargetTags)
{
	if (!HasAnyMatchingGameplayTags(TargetTags))
	{
		AddLooseGameplayTags(TargetTags);
		return true;
	}
	return false;
}