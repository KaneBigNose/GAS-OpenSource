// Made by LSH

#include "GameInstance/BFGameInstance.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

UBFGameInstance::UBFGameInstance(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	BFGameplayTags::InitGameplayTags();
}