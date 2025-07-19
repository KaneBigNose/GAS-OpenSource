// Made by LSH

#include "AI/BT_Task/Setting/BFPlayerTargeting.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Character/Character/BFCharacter.h"

UBFPlayerTargeting::UBFPlayerTargeting()
{
	NodeName = TEXT("Player Targeting");
}

EBTNodeResult::Type UBFPlayerTargeting::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BBComponent = OwnerComp.GetBlackboardComponent();

	if (BBComponent->GetValueAsObject(BlackboardKey.SelectedKeyName))
	{
		return EBTNodeResult::Succeeded;
	}

	ABFCharacter* TargetPlayer = Cast<ABFCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!TargetPlayer)
	{
		return EBTNodeResult::Failed;
	}

	BBComponent->SetValueAsObject(BlackboardKey.SelectedKeyName, TargetPlayer);

	return EBTNodeResult::Succeeded;
}