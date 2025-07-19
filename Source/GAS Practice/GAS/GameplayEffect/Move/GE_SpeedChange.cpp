// Made by LSH

#include "GAS/GameplayEffect/Move/GE_SpeedChange.h"
#include "GAS/AttributeSet/BFAttributeSet.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

UGE_SpeedChange::UGE_SpeedChange()
{
	DurationPolicy = EGameplayEffectDurationType::Instant;

    FGameplayModifierInfo SpeedModifier;
    SpeedModifier.Attribute = UBFAttributeSet::GetWalkSpeedAttribute();
    SpeedModifier.ModifierOp = EGameplayModOp::Multiplicitive;

    FSetByCallerFloat SetbyCaller;
    SetbyCaller.DataTag = BFGameplayTags::Data::Speed;
    SpeedModifier.ModifierMagnitude = SetbyCaller;

    Modifiers.Add(SpeedModifier);
}