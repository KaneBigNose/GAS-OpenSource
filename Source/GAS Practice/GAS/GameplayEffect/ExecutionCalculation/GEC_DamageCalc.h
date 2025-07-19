// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GEC_DamageCalc.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UGEC_DamageCalc : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()
	
public:
	UGEC_DamageCalc();

protected:
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};