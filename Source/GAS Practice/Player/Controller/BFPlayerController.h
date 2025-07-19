// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BFPlayerController.generated.h"

class UInputAction;
struct FInputActionValue;

UCLASS()
class PROJECT_BOSSFIGHT_API ABFPlayerController : public APlayerController
{
	GENERATED_BODY()

#pragma region Base

public:
	ABFPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Player")
	TObjectPtr<class ABFPlayer> BFPlayer;

	UPROPERTY(EditAnywhere, Category = "Player")
	TObjectPtr<class UBFAbilitySystemComponent> ASC;

#pragma endregion

#pragma region Input

protected:
	void MoveTriggered(const FInputActionValue& InputValue);
	void MoveReleased(const FInputActionValue& InputValue);

	void LookTriggered(const FInputActionValue& InputValue);
	void LookReleased(const FInputActionValue& InputValue);

	void JumpStarted(const FInputActionValue& InputValue);

	void RunStarted(const FInputActionValue& InputValue);
	void RunReleased(const FInputActionValue& InputValue);

	void AttackStarted(const FInputActionValue& InputValue);

	void LockOnStarted(const FInputActionValue& InputValue);

protected:
	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<class UInputMappingContext> IMC_Default;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_Look;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_Jump;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_Run;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_Attack;

	UPROPERTY(EditAnywhere, Category = "Player|Input")
	TObjectPtr<UInputAction> IA_LockOn;

#pragma endregion

};