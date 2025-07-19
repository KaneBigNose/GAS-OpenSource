// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_Die.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UGA_Die : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UGA_Die();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
								 const FGameplayAbilityActorInfo* ActorInfo,
								 const FGameplayAbilityActivationInfo ActivationInfo,
								 const FGameplayEventData* TriggerEventData) override;
};