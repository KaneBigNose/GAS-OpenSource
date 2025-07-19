// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BFSideStep.generated.h"

UENUM(BlueprintType)
enum class EBFMoveDirection : uint8
{
	East  UMETA(DisplayName = "East"),
	West  UMETA(DisplayName = "West"),
	South UMETA(DisplayName = "South"),
	North UMETA(DisplayName = "North")
};

UCLASS()
class PROJECT_BOSSFIGHT_API UBFSideStep : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBFSideStep();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

public:
	UFUNCTION()
	void MoveCompleted(FAIRequestID RequestID, EPathFollowingResult::Type Result);

protected:
	UPROPERTY(EditAnywhere, Category = "Move")
	EBFMoveDirection MoveDirection;

	UPROPERTY(EditAnywhere, Category = "Move")
	float MoveDistance;

	UPROPERTY()
	TObjectPtr<UBehaviorTreeComponent> BT;
};