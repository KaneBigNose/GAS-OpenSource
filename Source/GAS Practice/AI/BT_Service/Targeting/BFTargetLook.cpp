// Made by LSH

#include "AI/BT_Service/Targeting/BFTargetLook.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/Character/BFCharacter.h"
#include "Kismet/KismetMathLibrary.h"

UBFTargetLook::UBFTargetLook()
{
	NodeName = TEXT("Target Look");

	Interval = 0.01f;

	RandomDeviation = 0.0f;
}

void UBFTargetLook::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ABFCharacter* Owner = Cast<ABFCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
	ABFCharacter* Target = Cast<ABFCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(BlackboardKey.SelectedKeyName));

	float RotationSpeed = 5.0f;
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Owner->GetActorLocation(), Target->GetActorLocation());
	FRotator TargetDirection = FMath::RInterpTo(Owner->GetActorRotation(), LookAtRotation, DeltaSeconds, RotationSpeed);

	TargetDirection.Pitch = 0.0f;
	TargetDirection.Roll = 0.0f;

	Owner->SetActorRotation(TargetDirection);
}