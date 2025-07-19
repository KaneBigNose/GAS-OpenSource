// Made by LSH

#include "Weapon/BFWeapon.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Character/Character/BFCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"

ABFWeapon::ABFWeapon(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	HitBox = CreateDefaultSubobject<UCapsuleComponent>(TEXT("HitBox"));
	HitBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HitBoxBeginOverlap);
	RootComponent = HitBox;
	ActiveCollision(false);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
}

void ABFWeapon::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	DrawDebugCapsule(GetWorld(), GetActorLocation(), HitBox->GetScaledCapsuleHalfHeight(), HitBox->GetScaledCapsuleRadius(), GetActorQuat(), FColor::Red, false, 0.0f, 0, 1.0f);
}

void ABFWeapon::ActiveCollision(bool bIsActive)
{
	if (bIsActive)
	{
		HitBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		HitBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void ABFWeapon::HitBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->IsA(ABFCharacter::StaticClass()))
	{
		return;
	}

	ABFCharacter* OwnerCharacter = Cast<ABFCharacter>(GetOwner());
	ABFCharacter* Target = Cast<ABFCharacter>(OtherActor);

	if (OwnerCharacter == Target)
	{
		return;
	}

	UBFAbilitySystemComponent* OwnerASC = Cast<UBFAbilitySystemComponent>(OwnerCharacter->GetAbilitySystemComponent());

	OwnerASC->ApplyGameplayEffect(Target, DamageEffectClass, DamageScale);

	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 0.05f);

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, [this]() {UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f); }, 0.01f, false);
}