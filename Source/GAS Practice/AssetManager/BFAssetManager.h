// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "BFAssetManager.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static UBFAssetManager& Get();
};