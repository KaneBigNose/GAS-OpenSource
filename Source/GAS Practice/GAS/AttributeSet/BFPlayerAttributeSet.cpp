// Made by LSH

#include "GAS/AttributeSet/BFPlayerAttributeSet.h"

UBFPlayerAttributeSet::UBFPlayerAttributeSet(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	InitMaxHP(1000.0f);
	InitCurrentHP(1000.0f);

	InitMaxStamina(1000.0f);
	InitCurrentStamina(1000.0f);

	InitWalkSpeed(300.0f);
	InitRunSpeed(600.0f);

	InitDamage(100.0f);
	InitArmor(0.0f);

	InitCurrentCombo(1);
	InitMaxCombo(4);
}

void UBFPlayerAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetCurrentComboAttribute())
	{
		if (CurrentCombo.GetCurrentValue() > MaxCombo.GetCurrentValue())
		{
			CurrentCombo.SetCurrentValue(1);
		}
	}
}