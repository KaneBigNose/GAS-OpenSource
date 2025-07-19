// Made by LSH

#pragma once

#include "AbilitySystemGlobals.h"
#include "BFAbilitySystemGlobals.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFAbilitySystemGlobals : public UAbilitySystemGlobals
{
	GENERATED_BODY()
	
public:
	virtual FGameplayEffectContext* AllocGameplayEffectContext() const override;
};