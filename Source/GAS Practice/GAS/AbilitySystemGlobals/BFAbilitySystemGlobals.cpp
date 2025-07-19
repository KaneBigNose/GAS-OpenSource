// Made by LSH

#include "GAS/AbilitySystemGlobals/BFAbilitySystemGlobals.h"
#include "GAS/GameplayEffect/EffectContext/BFEffectContext.h"

FGameplayEffectContext* UBFAbilitySystemGlobals::AllocGameplayEffectContext() const
{
	return new FBFEffectContext();
}