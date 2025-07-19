// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BFTagManagement.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFTagManagement : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBFTagManagement();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere)
	struct FGameplayTag TargetTag;

	UPROPERTY(EditAnywhere)
	bool bIsAdd;
};