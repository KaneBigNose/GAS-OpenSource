// Made by LSH

#include "Player/Character/BFPlayer.h"
#include "Player/State/BFPlayerState.h"
#include "Player/Controller/BFPlayerController.h"
#include "Player/Camera/BFPlayerCameraComponent.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#pragma region Base

ABFPlayer::ABFPlayer(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	BFCameraComponent = CreateDefaultSubobject<UBFPlayerCameraComponent>(TEXT("BFCameraComponent"));

	GetMesh()->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));

	BFSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("BFSpringArm"));
	BFSpringArm->SetupAttachment(RootComponent);
	BFSpringArm->TargetArmLength = 500;
	BFSpringArm->SetRelativeLocationAndRotation(FVector(150, 0, 0), FRotator(0, 0, 0));
	BFSpringArm->bUsePawnControlRotation = true;

	BFCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("BFCamera"));
	BFCamera->SetupAttachment(BFSpringArm);
	BFCamera->bUsePawnControlRotation = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;

	LockOnBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LockOnBox"));
	LockOnBox->SetupAttachment(RootComponent);
	LockOnBox->SetRelativeLocation(FVector(500, 0, 0));
	LockOnBox->SetBoxExtent(FVector(500, 500, 200));
}

void ABFPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (!BFPlayerController)
	{
		BFPlayerController = Cast<ABFPlayerController>(GetController());
	}
}

void ABFPlayer::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!BFPlayerState)
	{
		BFPlayerState = GetPlayerState<ABFPlayerState>();
	}

	GetCharacterMovement()->MaxWalkSpeed = BFPlayerState->GetPlayerAttributeSet()->GetWalkSpeed();

	BFPlayerState->SetBFPlayer(this);

	ASC = Cast<UBFAbilitySystemComponent>(BFPlayerState->GetAbilitySystemComponent());
	ASC->InitAbilityActorInfo(BFPlayerState, this);

	GiveAbilities();
}

#pragma endregion