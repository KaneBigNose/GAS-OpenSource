// Made by LSH

#include "GAS/AttributeSet/BFAttributeSet.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "Character/Character/BFCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/State/BFPlayerState.h"

void UBFAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	ABFCharacter* Owner;

	if (GetOwningActor()->IsA(ABFPlayerState::StaticClass()))
	{
		Owner = Cast<ABFCharacter>(Cast<ABFPlayerState>(GetOwningActor())->GetBFPlayer());
	}
	else
	{
		Owner = Cast<ABFCharacter>(GetOwningActor());
	}

	UBFAbilitySystemComponent* OwnerASC = Cast<UBFAbilitySystemComponent>(Owner->GetAbilitySystemComponent());

	if (Data.EvaluatedData.Attribute == GetWalkSpeedAttribute())
	{
		Owner->GetCharacterMovement()->MaxWalkSpeed = WalkSpeed.GetCurrentValue();

		if (WalkSpeed.GetCurrentValue() == RunSpeed.GetCurrentValue())
		{
			Owner->bUseControllerRotationYaw = false;
			Owner->GetCharacterMovement()->bOrientRotationToMovement = true;
		}
		else
		{
			Owner->bUseControllerRotationYaw = true;
			Owner->GetCharacterMovement()->bOrientRotationToMovement = false;
		}
	}
	else if (Data.EvaluatedData.Attribute == GetCurrentHPAttribute())
	{
		if (GetCurrentHP() > 0)
		{
			OwnerASC->ActiveAbilitiesByTag(BFGameplayTags::State::Hitted);
		}
		else
		{
			OwnerASC->ActiveAbilitiesByTag(BFGameplayTags::State::Die);
		}
	}
}