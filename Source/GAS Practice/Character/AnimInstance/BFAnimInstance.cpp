// Made by LSH

#include "Character/AnimInstance/BFAnimInstance.h"
#include "Character/Character/BFCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

#pragma region Base

void UBFAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	OwnerCharacter = Cast<ABFCharacter>(GetOwningActor());

	if (!OwnerCharacter)
	{
		return;
	}

	OwnerASC = Cast<UBFAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent());

	OwnerMovementComponent = OwnerCharacter->GetCharacterMovement();
	OwnerMoveSpeed = OwnerMovementComponent->MaxWalkSpeed;
}

void UBFAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	CalculateStateMachine();
}

#pragma endregion

#pragma region State Machine

void UBFAnimInstance::CalculateStateMachine()
{
	if (!OwnerCharacter || !OwnerMovementComponent || !OwnerASC)
	{
		return;
	}

	FVector Dir = OwnerCharacter->GetVelocity();
	MoveDirection = FVector2D(OwnerCharacter->GetActorRotation().UnrotateVector(Dir));
	MoveDirection.Normalize();

	bIsMove = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Move);
	bIsJump = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Jump);
	bIsRun = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Run);
	bIsHit = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Hitted);
	bIsDie = OwnerASC->HasMatchingGameplayTag(BFGameplayTags::State::Die);
}

#pragma endregion