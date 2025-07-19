// Made by LSH

#include "AI/BT_Service/Calculation/BFTargetDistance.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/Character/BFCharacter.h"

UBFTargetDistance::UBFTargetDistance()
{
	NodeName = TEXT("Target Distance");

	Interval = 0.1f;

	RandomDeviation = 0.f;
}

void UBFTargetDistance::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ABFCharacter* Owner = Cast<ABFCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	ABFCharacter* Target = Cast<ABFCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	float Distance = FVector::Distance(Owner->GetActorLocation(), Target->GetActorLocation());

	OwnerComp.GetBlackboardComponent()->SetValueAsFloat(FName(TEXT("Distance")), Distance);
}