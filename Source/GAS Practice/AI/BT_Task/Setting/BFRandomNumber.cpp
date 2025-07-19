// Made by LSH

#include "AI/BT_Task/Setting/BFRandomNumber.h"
#include "BehaviorTree/BlackboardComponent.h"

UBFRandomNumber::UBFRandomNumber()
{
	NodeName = TEXT("Random Number");
}

EBTNodeResult::Type UBFRandomNumber::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	UBlackboardComponent* BBComponent = OwnerComp.GetBlackboardComponent();
	int8 RandomInt = FMath::RandRange(0, MaxRange);

	BBComponent->SetValueAsInt(BlackboardKey.SelectedKeyName, RandomInt);

	return EBTNodeResult::Succeeded;
}