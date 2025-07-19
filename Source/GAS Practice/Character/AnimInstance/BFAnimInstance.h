// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BFAnimInstance.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

#pragma region Base

protected:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	TObjectPtr<class ABFCharacter> OwnerCharacter;

	UPROPERTY()
	TObjectPtr<class UBFAbilitySystemComponent> OwnerASC;

	UPROPERTY()
	TObjectPtr<class UCharacterMovementComponent> OwnerMovementComponent;

#pragma endregion

#pragma region State Machine

protected:
	void CalculateStateMachine();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsJump = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsRun = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDie = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calc")
	FVector2D MoveDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Calc")
	float OwnerMoveSpeed;

#pragma endregion

};