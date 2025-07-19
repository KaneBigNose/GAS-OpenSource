// Made by LSH

#include "Character/Character/BFCharacter.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "Weapon/BFWeapon.h"

#pragma region Base

ABFCharacter::ABFCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABFCharacter::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapons();
}

#pragma endregion

#pragma region GAS

UAbilitySystemComponent* ABFCharacter::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent>(ASC);
}

void ABFCharacter::GiveAbilities()
{
	if (!ASC)
	{
		return;
	}

	for (auto CharacterAbilitie : CharacterAbilities)
	{
		FGameplayAbilitySpec AbilitySpec(CharacterAbilitie, 1, INDEX_NONE);

		ASC->GiveAbility(AbilitySpec);
	}
}

#pragma endregion

#pragma region Weapon

void ABFCharacter::SpawnWeapons()
{
	int8 SocketIndex = 0;

	for (auto WeaponClass : WeaponClasses)
	{
		ABFWeapon* SpawnedWeapon = GetWorld()->SpawnActor<ABFWeapon>(WeaponClass);
		SpawnedWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, WeaponSocketNames[SocketIndex++]);
		SpawnedWeapon->SetOwner(this);

		SpawnedWeapons.AddUnique(SpawnedWeapon);
	}
}

#pragma endregion