// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BFPlayerCameraComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECT_BOSSFIGHT_API UBFPlayerCameraComponent : public UActorComponent
{
	GENERATED_BODY()

#pragma region Base

public:
	UBFPlayerCameraComponent();

protected:
	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFPlayer|Base")
	TObjectPtr<class ABFPlayer> BFPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFPlayer|Base")
	TObjectPtr<class ABFPlayerController> BFPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFPlayer|Base")
	TObjectPtr<class UBFAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFPlayer|Attach")
	TObjectPtr<class UCameraComponent> BFCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFPlayer|Attach")
	TObjectPtr<class USpringArmComponent> BFSpringArm;

#pragma endregion

#pragma region Auto Zoom

protected:
	bool CheckNearByWall();

	void AdjustSpringArm(float DeltaTime, bool bIsBack);

protected:
	UPROPERTY()
	FVector OriginalArmLocation;

#pragma endregion

#pragma region Lock On

public:
	UFUNCTION()
	void LockOnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

protected:
	bool CheckTargetLockOn();

	void SetCameraLockOn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBoxComponent> LockOnBox;

	UPROPERTY()
	TObjectPtr<class ABFCharacter> LockOnTarget;

#pragma endregion

};