// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "BFGameInstance.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UBFGameInstance(const FObjectInitializer& ObjectInitializer);
};