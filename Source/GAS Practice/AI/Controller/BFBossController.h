// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BFBossController.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFBossController : public AAIController
{
	GENERATED_BODY()
	
public:
	ABFBossController();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	TObjectPtr<class UBlackboardData> BB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	TObjectPtr<class UBlackboardComponent> BBComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base")
	TObjectPtr<class UBehaviorTree> BT;
};