// Made by LSH

#include "GAS/GameplayEffect/ExecutionCalculation/GEC_DamageCalc.h"
#include "GAS/GameplayEffect/EffectContext/BFEffectContext.h"
#include "GAS/AttributeSet/BFAttributeSet.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

struct FDamageCapture
{
	static FGameplayEffectAttributeCaptureDefinition Damage;
	static FGameplayEffectAttributeCaptureDefinition Armor;

	FDamageCapture()
	{
		Damage = FGameplayEffectAttributeCaptureDefinition(UBFAttributeSet::GetDamageAttribute(), EGameplayEffectAttributeCaptureSource::Source, false);
		Armor = FGameplayEffectAttributeCaptureDefinition(UBFAttributeSet::GetArmorAttribute(), EGameplayEffectAttributeCaptureSource::Target, false);
	}
};

FGameplayEffectAttributeCaptureDefinition FDamageCapture::Damage;
FGameplayEffectAttributeCaptureDefinition FDamageCapture::Armor;

static const FDamageCapture& DamageCapture()
{
	static const FDamageCapture DamageCap;

	return DamageCap;
}

UGEC_DamageCalc::UGEC_DamageCalc()
{
	RelevantAttributesToCapture.Add(DamageCapture().Damage);
	RelevantAttributesToCapture.Add(DamageCapture().Armor);
}

void UGEC_DamageCalc::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	Super::Execute_Implementation(ExecutionParams, OutExecutionOutput);

	const FGameplayEffectSpec& Spec = ExecutionParams.GetOwningSpec();
	const FGameplayEffectContextHandle& ContextHandle = Spec.GetContext();
	const FBFEffectContext* BFContext = static_cast<const FBFEffectContext*>(ContextHandle.Get());

	FAggregatorEvaluateParameters EvalParams;
	EvalParams.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvalParams.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float BaseDamage;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageCapture().Damage, EvalParams, BaseDamage);
	BaseDamage *= BFContext->ValueScale;

	float Armor;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageCapture().Armor, EvalParams, Armor);

	float FinalDamage = BaseDamage * (100.f / (100.f + Armor));

	if (FinalDamage > 0.0f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(UBFAttributeSet::GetCurrentHPAttribute(), EGameplayModOp::Additive, -FinalDamage));
	}
}