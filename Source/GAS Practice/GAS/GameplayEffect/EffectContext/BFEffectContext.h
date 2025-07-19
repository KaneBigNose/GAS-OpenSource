// Made by LSH

#pragma once

#include "GameplayEffectTypes.h"
#include "BFEffectContext.generated.h"

USTRUCT()
struct PROJECT_BOSSFIGHT_API FBFEffectContext : public FGameplayEffectContext
{
	GENERATED_BODY()
	
public:
	virtual UScriptStruct* GetScriptStruct() const override { return StaticStruct(); }

	virtual FGameplayEffectContext* Duplicate() const override
	{
		FBFEffectContext* NewContext = new FBFEffectContext(*this);
		return NewContext;
	}

public:
	UPROPERTY()
	float ValueScale = 1.0f;
};