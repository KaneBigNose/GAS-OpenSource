// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Weapon/BFWeapon.h"
#include "BFRanged.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFRanged : public ABFWeapon
{
	GENERATED_BODY()
	
public:
	ABFRanged(const FObjectInitializer& ObjectInitializer);

public:
	virtual void ActiveCollision(bool bIsActive) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ABFProjectile> ProjectileClass;
};