// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BFRandomNumber.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFRandomNumber : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBFRandomNumber();
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere)
	int8 MaxRange;
};