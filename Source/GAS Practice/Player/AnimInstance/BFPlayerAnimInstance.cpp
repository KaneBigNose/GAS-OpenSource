// Made by LSH

#include "Player/AnimInstance/BFPlayerAnimInstance.h"
#include "Character/Character/BFCharacter.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

#pragma region Base

void UBFPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!OwnerCharacter)
	{
		return;
	}

	if (!OwnerASC)
	{
		OwnerASC = Cast<UBFAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent());

		return;
	}

	bIsLockOn = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::LockOn);

	SetIKRigInfo(DeltaSeconds);
}

#pragma endregion

#pragma region IK Rig

void UBFPlayerAnimInstance::SetIKRigInfo(float DeltaSeconds)
{
	if (OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Jump))
	{
		FootLocationL = FVector::ZeroVector;
		FootLocationR = FVector::ZeroVector;
		FootRotationL = FRotator::ZeroRotator;
		FootRotationR = FRotator::ZeroRotator;
		PelvisLocation = FMath::VInterpTo(PelvisLocation, FVector::ZeroVector, DeltaSeconds, 12.0f);
		return;
	}

	USkeletalMeshComponent* OwnerMesh = OwnerCharacter->GetMesh();
	FVector CurFootLocL = OwnerMesh->GetSocketLocation(SocketFootL);
	FVector CurFootLocR = OwnerMesh->GetSocketLocation(SocketFootR);
	FRotator CurFootRotL = OwnerMesh->GetSocketRotation(SocketFootL);
	FRotator CurFootRotR = OwnerMesh->GetSocketRotation(SocketFootR);
	FVector CurRootLoc = OwnerMesh->GetSocketLocation(SocketRoot);

	FootTrace(CurFootLocL, CurFootRotL, CurRootLoc);
	FootTrace(CurFootLocR, CurFootRotR, CurRootLoc);

	FootLocationL = FMath::VInterpTo(FootLocationL, CurFootLocL, DeltaSeconds, 12.0f);
	FootLocationR = FMath::VInterpTo(FootLocationR, CurFootLocR, DeltaSeconds, 12.0f);
	FootRotationL = FMath::RInterpTo(FootRotationL, CurFootRotL, DeltaSeconds, 12.0f);
	FootRotationR = FMath::RInterpTo(FootRotationR, CurFootRotR, DeltaSeconds, 12.0f);

	float MinFootOffsetZ = FMath::Min(FootLocationL.Z, FootLocationR.Z);
	PelvisLocation = FMath::VInterpTo(PelvisLocation, FVector(0, 0, MinFootOffsetZ), DeltaSeconds, 12.0f);
}

void UBFPlayerAnimInstance::FootTrace(OUT FVector& FootLocation, OUT FRotator& FootRotation, const FVector RootLocation)
{
	FHitResult HitResult;
	FVector Start = FVector(FootLocation.X, FootLocation.Y, RootLocation.Z + 30);
	FVector End = FVector(FootLocation.X, FootLocation.Y, RootLocation.Z - 50);
	float Radius = 3.0f;

	FCollisionQueryParams Params;
	Params.AddIgnoredActor(OwnerCharacter);

	bool bHit = GetWorld()->SweepSingleByChannel(OUT HitResult, Start, End, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(Radius), Params);

	if (bHit)
	{
		FootLocation = FVector(0, 0, HitResult.ImpactPoint.Z - RootLocation.Z);
		FootRotation = FRotationMatrix::MakeFromZ(HitResult.Normal).Rotator();
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1.0f);
		DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 5.0f, 8, FColor::Green, false, -1.0f);
	}
	else
	{
		FootLocation = FVector::ZeroVector;
		FootRotation = FRotator::ZeroRotator;
	}
}

#pragma endregion