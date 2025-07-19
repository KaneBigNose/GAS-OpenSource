// Made by LSH

#include "Player/Controller/BFPlayerController.h"
#include "Player/Character/BFPlayer.h"
#include "Player/State/BFPlayerState.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/KismetMathLibrary.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"

#pragma region Base

ABFPlayerController::ABFPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABFPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (!BFPlayer)
	{
		BFPlayer = Cast<ABFPlayer>(GetPawn());

		ASC = Cast<UBFAbilitySystemComponent>(BFPlayer->GetAbilitySystemComponent());
	}

	if (auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(IMC_Default, 0);
	}
}

void ABFPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ThisClass::MoveTriggered);
		EIC->BindAction(IA_Move, ETriggerEvent::Canceled, this, &ThisClass::MoveReleased);
		EIC->BindAction(IA_Move, ETriggerEvent::Completed, this, &ThisClass::MoveReleased);

		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ThisClass::LookTriggered);
		EIC->BindAction(IA_Look, ETriggerEvent::Canceled, this, &ThisClass::LookReleased);
		EIC->BindAction(IA_Look, ETriggerEvent::Completed, this, &ThisClass::LookReleased);

		EIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &ThisClass::JumpStarted);

		EIC->BindAction(IA_Run, ETriggerEvent::Started, this, &ThisClass::RunStarted);
		EIC->BindAction(IA_Run, ETriggerEvent::Canceled, this, &ThisClass::RunReleased);
		EIC->BindAction(IA_Run, ETriggerEvent::Completed, this, &ThisClass::RunReleased);

		EIC->BindAction(IA_Attack, ETriggerEvent::Started, this, &ThisClass::AttackStarted);

		EIC->BindAction(IA_LockOn, ETriggerEvent::Started, this, &ThisClass::LockOnStarted);
	}
}

#pragma endregion

#pragma region Move

void ABFPlayerController::MoveTriggered(const FInputActionValue& InputValue)
{
	if (ASC->HasMatchingGameplayTag(BFGameplayTags::State::Attack) ||
		ASC->HasMatchingGameplayTag(BFGameplayTags::State::Blocked) ||
		ASC->HasMatchingGameplayTag(BFGameplayTags::State::Hitted) ||
		ASC->HasMatchingGameplayTag(BFGameplayTags::State::Die))
	{
		return;
	}

	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Move);

	FVector2D MovementVector = InputValue.Get<FVector2D>();
	FRotator InputRotator = GetControlRotation();

	if (MovementVector != FVector2D::ZeroVector)
	{
		FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(FRotator(0, InputRotator.Yaw, 0));
		BFPlayer->AddMovementInput(ForwardDirection, MovementVector.X);

		FVector RightDirection = UKismetMathLibrary::GetRightVector(FRotator(0, InputRotator.Yaw, 0));
		BFPlayer->AddMovementInput(RightDirection, MovementVector.Y);
	}
}

void ABFPlayerController::MoveReleased(const FInputActionValue& InputValue)
{
	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Move);
}

#pragma endregion

#pragma region Look

void ABFPlayerController::LookTriggered(const FInputActionValue& InputValue)
{
	if (ASC->HasMatchingGameplayTag(BFGameplayTags::State::Attack) ||
		ASC->HasMatchingGameplayTag(BFGameplayTags::State::Hitted) ||
		ASC->HasMatchingGameplayTag(BFGameplayTags::State::Die))
	{
		return;
	}

	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Look);

	FVector2D LookVector = InputValue.Get<FVector2D>();

	if (LookVector != FVector2D::ZeroVector)
	{
		BFPlayer->AddControllerYawInput(LookVector.X);
		BFPlayer->AddControllerPitchInput(LookVector.Y);
	}
}

void ABFPlayerController::LookReleased(const FInputActionValue& InputValue)
{
	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Look);
}

#pragma endregion

#pragma region Jump

void ABFPlayerController::JumpStarted(const FInputActionValue& InputValue)
{
	ASC->ActiveAbilitiesByTag(BFGameplayTags::State::Jump);
}

#pragma endregion

#pragma region Run

void ABFPlayerController::RunStarted(const FInputActionValue& InputValue)
{
	ASC->ActiveAbilitiesByTag(BFGameplayTags::State::Run);
}

void ABFPlayerController::RunReleased(const FInputActionValue& InputValue)
{
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Run);
}

#pragma endregion

#pragma region Attack

void ABFPlayerController::AttackStarted(const FInputActionValue& InputValue)
{
	int8 Combo = Cast<UBFPlayerAttributeSet>(ASC->GetAttributeSet(UBFPlayerAttributeSet::StaticClass()))->GetCurrentCombo();
	FName ComboName = FName(*FString::Printf(TEXT("Combo%d"), Combo));

	ASC->ActiveAbilitiesByTag(BFGameplayTags::FindTagByFName(ComboName));
}

#pragma endregion

#pragma region Lock On

void ABFPlayerController::LockOnStarted(const FInputActionValue& InputValue)
{
	ASC->ActiveAbilitiesByTag(BFGameplayTags::State::LockOn);
}

#pragma endregion