// Made by LSH

#include "AI/BT_Task/Ability/BFActiveAbility.h"
#include "AIController.h"
#include "Character/Character/BFCharacter.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"

UBFActiveAbility::UBFActiveAbility()
{
	NodeName = TEXT("Active Ability");
}

EBTNodeResult::Type UBFActiveAbility::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	ABFCharacter* Owner = Cast<ABFCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(Owner->GetAbilitySystemComponent());

	if (bIsActive)
	{
		ASC->ActiveAbilitiesByTag(TargetTag);
	}
	else
	{
		ASC->CancelAbilitiesByTag(TargetTag);
	}

	return EBTNodeResult::Succeeded;
}