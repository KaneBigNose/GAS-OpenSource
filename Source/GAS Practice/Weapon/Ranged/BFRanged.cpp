// Made by LSH

#include "Weapon/Ranged/BFRanged.h"
#include "Weapon/Projectile/BFProjectile.h"
#include "Character/Character/BFCharacter.h"
#include "Components/CapsuleComponent.h"

ABFRanged::ABFRanged(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	WeaponMesh->SetRelativeScale3D(FVector(1, 1, 1));
}

void ABFRanged::ActiveCollision(bool bIsActive)
{
	Super::ActiveCollision(bIsActive);

	/*if (bIsActive)
	{
		ABFCharacter* OwnerCharacter = Cast<ABFCharacter>(GetOwner());
		FVector SpawnLocation = OwnerCharacter->GetActorLocation() + OwnerCharacter->GetActorForwardVector() * 100.f;
		ABFProjectile* SpawnedProjectile = GetWorld()->SpawnActor<ABFProjectile>(ProjectileClass, SpawnLocation, OwnerCharacter->GetActorRotation());

		SpawnedProjectile->GetHitBoxComponent()->IgnoreActorWhenMoving(OwnerCharacter, true);
	}*/
}