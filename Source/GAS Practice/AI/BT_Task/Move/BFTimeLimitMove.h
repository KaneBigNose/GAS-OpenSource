// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_MoveTo.h"
#include "BFTimeLimitMove.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFTimeLimitMove : public UBTTask_MoveTo
{
	GENERATED_BODY()
	
public:
	UBFTimeLimitMove();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere)
	float TimeLimitDuration;
};