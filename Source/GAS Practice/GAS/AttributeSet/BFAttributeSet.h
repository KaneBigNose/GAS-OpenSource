// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "BFAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class PROJECT_BOSSFIGHT_API UBFAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

protected:
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData CurrentHP;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, CurrentHP)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData MaxHP;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, MaxHP)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData WalkSpeed;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, WalkSpeed)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Basic")
	FGameplayAttributeData RunSpeed;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, RunSpeed)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, Damage)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UBFAttributeSet, Armor)
};