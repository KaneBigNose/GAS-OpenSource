// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GAS/AttributeSet/BFAttributeSet.h"
#include "BFPlayerAttributeSet.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFPlayerAttributeSet : public UBFAttributeSet
{
	GENERATED_BODY()
	
public:
	UBFPlayerAttributeSet(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData CurrentStamina;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, CurrentStamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, MaxStamina)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FGameplayAttributeData CurrentCombo;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, CurrentCombo)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FGameplayAttributeData MaxCombo;
	ATTRIBUTE_ACCESSORS(UBFPlayerAttributeSet, MaxCombo)
};