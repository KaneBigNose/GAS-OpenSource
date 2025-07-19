// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GA_FrontJump.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UGA_FrontJump : public UGameplayAbility
{
	GENERATED_BODY()
	
public:
	UGA_FrontJump();

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle,
								 const FGameplayAbilityActorInfo* ActorInfo,
								 const FGameplayAbilityActivationInfo ActivationInfo,
								 const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle,
							const FGameplayAbilityActorInfo* ActorInfo,
							const FGameplayAbilityActivationInfo ActivationInfo,
							bool bReplicateEndAbility,
							bool bWasCancelled) override;

protected:
	FTimerHandle DelayHandle;

	UPROPERTY(EditAnywhere, Category = "Calc")
	float ForwardForce;

	UPROPERTY(EditAnywhere, Category = "Calc")
	float UpwardForce;

	UPROPERTY(EditAnywhere, Category = "Calc")
	float DelayTime;
};