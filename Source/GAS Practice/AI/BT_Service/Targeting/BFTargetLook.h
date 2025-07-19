// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BFTargetLook.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFTargetLook : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBFTargetLook();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};