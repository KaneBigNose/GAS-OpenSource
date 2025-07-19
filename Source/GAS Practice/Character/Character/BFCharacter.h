// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Delegates/DelegateCombinations.h"
#include "BFCharacter.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

#pragma region Base

public:
	ABFCharacter(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

#pragma endregion

#pragma region GAS

public:
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	void GiveAbilities();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|GAS")
	TArray<TSubclassOf<class UGameplayAbility>> CharacterAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|GAS")
	TObjectPtr<class UBFAbilitySystemComponent> ASC;

#pragma endregion

#pragma region Animation

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|Animation")
	float HitAngle = 0.0f;

#pragma endregion

#pragma region Weapon

public:
	TArray<TObjectPtr<class ABFWeapon>> GetWeapons() { return SpawnedWeapons; }

protected:
	virtual void SpawnWeapons();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|Weapon")
	TArray<TSubclassOf<class ABFWeapon>> WeaponClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|Weapon")
	TArray<FName> WeaponSocketNames;

	UPROPERTY()
	TArray<TObjectPtr<class ABFWeapon>> SpawnedWeapons;

#pragma endregion

};