// Made by LSH

#include "AI/BT_Task/Move/BFTimeLimitMove.h"

UBFTimeLimitMove::UBFTimeLimitMove()
{
	NodeName = TEXT("Time Limit Move");
}

EBTNodeResult::Type UBFTimeLimitMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	FTimerHandle TimeLimitHandle;
	GetWorld()->GetTimerManager().SetTimer(TimeLimitHandle, [this, &OwnerComp]() {FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded); }, TimeLimitDuration, false);

	return EBTNodeResult::InProgress;
}