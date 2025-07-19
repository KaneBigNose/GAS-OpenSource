// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BFAbilitySystemComponent.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

protected:
	virtual FGameplayEffectContextHandle MakeEffectContext() const override;

public:
	void ActiveAbilitiesByTag(struct FGameplayTag ActiveTag);
	void CancelAbilitiesByTag(struct FGameplayTag CancelTag);

	FActiveGameplayEffectHandle ApplyGameplayEffect(class ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass);
	FActiveGameplayEffectHandle ApplyGameplayEffect(class ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass, FGameplayTag DataTag, float EffectValue);
	FActiveGameplayEffectHandle ApplyGameplayEffect(class ABFCharacter* Target, TSubclassOf<UGameplayEffect> ApplyEffectClass, float ValueScale);

	bool AddUniqueGameplayTag(struct FGameplayTag TargetTag);
	bool AddUniqueGameplayTags(struct FGameplayTagContainer TargetTags);
};