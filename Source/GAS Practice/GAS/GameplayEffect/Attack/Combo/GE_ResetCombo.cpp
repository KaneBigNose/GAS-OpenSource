// Made by LSH

#include "GAS/GameplayEffect/Attack/Combo/GE_ResetCombo.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"

UGE_ResetCombo::UGE_ResetCombo()
{
    DurationPolicy = EGameplayEffectDurationType::Instant;

    FGameplayModifierInfo ComboModifier;
    ComboModifier.Attribute = UBFPlayerAttributeSet::GetCurrentComboAttribute();
    ComboModifier.ModifierOp = EGameplayModOp::Override;
    ComboModifier.ModifierMagnitude = FScalableFloat(1.f);

    Modifiers.Add(ComboModifier);
}