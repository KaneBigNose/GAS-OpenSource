// Made by LSH

#include "AI/BT_Task/Setting/BFTagManagement.h"
#include "AIController.h"
#include "Character/Character/BFCharacter.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"

UBFTagManagement::UBFTagManagement()
{
	NodeName = TEXT("GameplayTag Manage");
}

EBTNodeResult::Type UBFTagManagement::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (!TargetTag.IsValid())
	{
		return EBTNodeResult::Failed;
	}
	
	ABFCharacter* Owner = Cast<ABFCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(Owner->GetAbilitySystemComponent());

	if (bIsAdd)
	{
		ASC->AddUniqueGameplayTag(TargetTag);
	}
	else
	{
		ASC->RemoveLooseGameplayTag(TargetTag);
	}

	return EBTNodeResult::Succeeded;
}