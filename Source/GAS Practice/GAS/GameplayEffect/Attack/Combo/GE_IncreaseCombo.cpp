// Made by LSH

#include "GAS/GameplayEffect/Attack/Combo/GE_IncreaseCombo.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"

UGE_IncreaseCombo::UGE_IncreaseCombo()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;

    FGameplayModifierInfo ComboModifier;
    ComboModifier.Attribute = UBFPlayerAttributeSet::GetCurrentComboAttribute();
    ComboModifier.ModifierOp = EGameplayModOp::Additive;
    ComboModifier.ModifierMagnitude = FScalableFloat(1.f);

    Modifiers.Add(ComboModifier);
}