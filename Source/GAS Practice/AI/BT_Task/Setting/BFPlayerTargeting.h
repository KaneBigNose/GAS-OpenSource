// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BFPlayerTargeting.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFPlayerTargeting : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBFPlayerTargeting();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};