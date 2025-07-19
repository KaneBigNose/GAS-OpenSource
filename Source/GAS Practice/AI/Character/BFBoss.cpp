// Made by LSH

#include "AI/Character/BFBoss.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/AttributeSet/BFBossAttributeSet.h"

ABFBoss::ABFBoss(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	GetCapsuleComponent()->SetCapsuleSize(60, 150);

	GetMesh()->SetRelativeLocationAndRotation(FVector(-20, 0, -150), FRotator(0, -90, 0));
	GetMesh()->SetRelativeScale3D(FVector(2, 2, 2));

	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	BossAttributeSet = CreateDefaultSubobject<UBFBossAttributeSet>(TEXT("BossAttributeSet"));

	ASC = CreateDefaultSubobject<UBFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->AddAttributeSetSubobject(BossAttributeSet.Get());
}

void ABFBoss::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	GetCharacterMovement()->MaxWalkSpeed = BossAttributeSet->GetWalkSpeed();

	ASC->InitAbilityActorInfo(this, this);

	GiveAbilities();
}