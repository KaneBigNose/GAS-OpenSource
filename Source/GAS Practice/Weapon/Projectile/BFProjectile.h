// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BFWeapon.h"
#include "BFProjectile.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFProjectile : public ABFWeapon
{
	GENERATED_BODY()

public:
	ABFProjectile(const FObjectInitializer& ObjectInitializer);

public:
	virtual void HitBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UProjectileMovementComponent> ProjectileComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ProjectileSpeed;
};