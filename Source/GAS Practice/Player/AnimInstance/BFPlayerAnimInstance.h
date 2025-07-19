// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Character/AnimInstance/BFAnimInstance.h"
#include "BFPlayerAnimInstance.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFPlayerAnimInstance : public UBFAnimInstance
{
	GENERATED_BODY()

#pragma region Base

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

#pragma endregion

#pragma region State Machine

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsLockOn = false;

#pragma endregion

#pragma region IK Rig

protected:
	void SetIKRigInfo(float DeltaSeconds);
	void FootTrace(OUT FVector& FootLocation, OUT FRotator& FootRotation, const FVector RootLocation);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK Rig")
	FVector FootLocationL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK Rig")
	FVector FootLocationR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK Rig")
	FRotator FootRotationL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK Rig")
	FRotator FootRotationR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "IK Rig")
	FVector PelvisLocation;

	FName SocketFootL = TEXT("foot_l");
	FName SocketFootR = TEXT("foot_r");
	FName SocketRoot = TEXT("root");

#pragma endregion

};