// Made by LSH

#include "AI/Controller/BFBossController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

ABFBossController::ABFBossController()
{
	PrimaryActorTick.bCanEverTick = false;

	BBComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BBComponent"));
}

void ABFBossController::BeginPlay()
{
	Super::BeginPlay();

	UBlackboardComponent* BBComponentRaw = BBComponent.Get();
	UseBlackboard(BB, BBComponentRaw);

	RunBehaviorTree(BT);
}