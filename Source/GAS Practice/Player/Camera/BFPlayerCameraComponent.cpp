// Made by LSH

#include "Player/Camera/BFPlayerCameraComponent.h"
#include "Player/Character/BFPlayer.h"
#include "Player/Controller/BFPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

#pragma region Base

UBFPlayerCameraComponent::UBFPlayerCameraComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBFPlayerCameraComponent::BeginPlay()
{
	Super::BeginPlay();

	BFPlayer = Cast<ABFPlayer>(GetOwner());
	BFCamera = BFPlayer->GetBFCamera();
	BFSpringArm = BFPlayer->GetBFSpringArm();

	OriginalArmLocation = BFSpringArm->GetRelativeLocation();

	BFSpringArm->bDoCollisionTest = true;
	BFSpringArm->ProbeChannel = ECollisionChannel::ECC_Pawn;

	LockOnBox = BFPlayer->GetLockOnBox();
	LockOnBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::LockOnBoxBeginOverlap);
}

void UBFPlayerCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!ASC)
	{
		ASC = Cast<UBFAbilitySystemComponent>(BFPlayer->GetAbilitySystemComponent());

		return;
	}

	if (CheckNearByWall() || ASC->HasMatchingGameplayTag(BFGameplayTags::State::Run))
	{
		AdjustSpringArm(DeltaTime, true);
	}
	else
	{
		AdjustSpringArm(DeltaTime, false);
	}

	if (CheckTargetLockOn())
	{
		SetCameraLockOn();
	}
}

#pragma endregion

#pragma region Auto Zoom

bool UBFPlayerCameraComponent::CheckNearByWall()
{
	FHitResult HitResult;
	FVector Start = BFPlayer->GetActorLocation();
	FVector End = Start + BFCamera->GetForwardVector() * 300.f;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(BFPlayer);

	bool bHit = GetWorld()->LineTraceSingleByChannel(OUT HitResult, Start, End, ECC_WorldStatic, Params);

	if (!bHit)
	{
		return false;
	}

	return true;
}

void UBFPlayerCameraComponent::AdjustSpringArm(float DeltaTime, bool bIsBack)
{
	FVector Start = BFSpringArm->GetRelativeLocation();

	if (bIsBack)
	{
		FVector End = FVector::ZeroVector;
		FVector Target = FMath::VInterpTo(Start, End, DeltaTime, 5);

		BFSpringArm->SetRelativeLocation(Target);
	}
	else
	{
		FVector End = OriginalArmLocation;
		FVector Target = FMath::VInterpTo(Start, End, DeltaTime, 5);

		BFSpringArm->SetRelativeLocation(Target);
	}
}

#pragma endregion

#pragma region Lock On

void UBFPlayerCameraComponent::LockOnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->IsA(ABFCharacter::StaticClass()))
	{
		return;
	}

	LockOnTarget = Cast<ABFCharacter>(OtherActor);
}

bool UBFPlayerCameraComponent::CheckTargetLockOn()
{
	return ASC->HasMatchingGameplayTag(BFGameplayTags::State::LockOn);
}

void UBFPlayerCameraComponent::SetCameraLockOn()
{
	if (!LockOnTarget)
	{
		ASC->CancelAbilitiesByTag(BFGameplayTags::State::LockOn);

		return;
	}

	if (!BFPlayerController)
	{
		BFPlayerController = BFPlayer->GetBFPlayerController();
	}

	FVector Direction = LockOnTarget->GetActorLocation() - BFPlayer->GetActorLocation();
	Direction = Direction.GetSafeNormal();

	FRotator TargetRotation = Direction.Rotation();
	TargetRotation.Pitch = BFPlayerController->GetControlRotation().Pitch;

	BFPlayerController->SetControlRotation(TargetRotation);
}

#pragma endregion