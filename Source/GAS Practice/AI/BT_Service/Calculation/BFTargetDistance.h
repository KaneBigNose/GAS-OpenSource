// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BFTargetDistance.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFTargetDistance : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBFTargetDistance();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};