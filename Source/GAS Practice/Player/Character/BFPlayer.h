// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Character/Character/BFCharacter.h"
#include "BFPlayer.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFPlayer : public ABFCharacter
{
	GENERATED_BODY()

#pragma region Base

public:
	ABFPlayer(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

public:
	TObjectPtr<class ABFPlayerController> GetBFPlayerController() { return BFPlayerController; }

	TObjectPtr<class ABFPlayerState> GetBFPlayerState() { return BFPlayerState; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|Basic")
	TObjectPtr<class ABFPlayerController> BFPlayerController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|Basic")
	TObjectPtr<class ABFPlayerState> BFPlayerState;

#pragma endregion

#pragma region Camera

public:
	TObjectPtr<class UCameraComponent> GetBFCamera() { return BFCamera; }
	TObjectPtr<class USpringArmComponent> GetBFSpringArm() { return BFSpringArm; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBFPlayerCameraComponent> BFCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UCameraComponent> BFCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class USpringArmComponent> BFSpringArm;

#pragma endregion

#pragma region Lock On

public:
	TObjectPtr<class UBoxComponent> GetLockOnBox() { return LockOnBox; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class UBoxComponent> LockOnBox;

#pragma endregion

};