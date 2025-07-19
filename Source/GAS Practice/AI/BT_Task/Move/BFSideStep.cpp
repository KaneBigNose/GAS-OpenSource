// Made by LSH

#include "AI/BT_Task/Move/BFSideStep.h"
#include "AIController.h"
#include "Character/Character/BFCharacter.h"

UBFSideStep::UBFSideStep()
{
	NodeName = TEXT("Side Step");
}

EBTNodeResult::Type UBFSideStep::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	BT = &OwnerComp;
	AAIController* AIController = OwnerComp.GetAIOwner();
	ABFCharacter* Owner = Cast<ABFCharacter>(AIController->GetCharacter());

	FVector DirectionVector;

	switch (MoveDirection)
	{
	case EBFMoveDirection::East:
		DirectionVector = Owner->GetActorRightVector();
		break;

	case EBFMoveDirection::West:
		DirectionVector = Owner->GetActorRightVector() * -1.0f;
		break;

	case EBFMoveDirection::South:
		DirectionVector = Owner->GetActorForwardVector() * -1.0f;
		break;

	case EBFMoveDirection::North:
		DirectionVector = Owner->GetActorForwardVector();
		break;
	}

	if (!AIController->ReceiveMoveCompleted.IsBound())
	{
		AIController->ReceiveMoveCompleted.AddDynamic(this, &ThisClass::MoveCompleted);
	}

	AIController->MoveToLocation(Owner->GetActorLocation() + DirectionVector * MoveDistance);

	FTimerHandle TimeLimitHandle;
	GetWorld()->GetTimerManager().SetTimer(TimeLimitHandle, [this, &OwnerComp]() {FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded); }, 1.0f, false);

	return EBTNodeResult::InProgress;
}

void UBFSideStep::MoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result)
{
	FinishLatentTask(*BT, EBTNodeResult::Succeeded);
}