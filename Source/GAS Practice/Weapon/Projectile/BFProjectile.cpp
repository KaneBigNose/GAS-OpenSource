// Made by LSH

#include "Weapon/Projectile/BFProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

ABFProjectile::ABFProjectile(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComponent"));
	ProjectileComponent->InitialSpeed = 1200.f;
	ProjectileComponent->MaxSpeed = 1200.f;
	ProjectileComponent->ProjectileGravityScale = 0.f;
	ProjectileComponent->Velocity = GetActorForwardVector() * ProjectileSpeed;

	ActiveCollision(true);
}

void ABFProjectile::HitBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::HitBoxBeginOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	Destroy();
}