// Made by LSH

#include "GAS/GameplayEffect/Attack/Damage/GE_Damage.h"
#include "GAS/GameplayEffect/ExecutionCalculation/GEC_DamageCalc.h"

UGE_Damage::UGE_Damage()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;

	FGameplayEffectExecutionDefinition ExecDef;
	ExecDef.CalculationClass = UGEC_DamageCalc::StaticClass();
	Executions.Add(ExecDef);
}