// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BFActiveAbility.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFActiveAbility : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBFActiveAbility();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere)
	struct FGameplayTag TargetTag;

	UPROPERTY(EditAnywhere)
	bool bIsActive;
};