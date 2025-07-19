// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BFWeapon.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFWeapon : public AActor
{
	GENERATED_BODY()

public:
	ABFWeapon(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void Tick(float DeltaSeconds) override;

public:
	TObjectPtr<class UCapsuleComponent> GetHitBoxComponent() { return HitBox; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UCapsuleComponent> HitBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UStaticMeshComponent> WeaponMesh;

public:
	virtual void ActiveCollision(bool bIsActive);

	UFUNCTION()
	virtual void HitBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SetDamageScale(float SettingValue) { DamageScale = SettingValue; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TSubclassOf<class UGameplayEffect> DamageEffectClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	float DamageScale = 1.0f;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	struct FGameplayTagContainer ActiveCollisionTags;
};