// Made by LSH

#include "AssetManager/BFAssetManager.h"

UBFAssetManager& UBFAssetManager::Get()
{
	UBFAssetManager* AssetManager = Cast<UBFAssetManager>(GEngine->AssetManager);

	return *AssetManager;
}