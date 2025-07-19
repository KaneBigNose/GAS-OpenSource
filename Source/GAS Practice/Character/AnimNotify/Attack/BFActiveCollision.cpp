// Made by LSH

#include "Character/AnimNotify/Attack/BFActiveCollision.h"
#include "Character/Character/BFCharacter.h"
#include "Weapon/BFWeapon.h"

void UBFActiveCollision::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	ABFCharacter* Owner = Cast<ABFCharacter>(MeshComp->GetOwner());
	if (!Owner)
	{
		return;
	}

	for (auto& FoundWeapon : Owner->GetWeapons())
	{
		if (FoundWeapon->ActiveCollisionTags.HasTag(CurrentComboTag))
		{
			FoundWeapon->SetDamageScale(DamageScale);
			FoundWeapon->ActiveCollision(true);
		}
	}
}

void UBFActiveCollision::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	ABFCharacter* Owner = Cast<ABFCharacter>(MeshComp->GetOwner());
	if (!Owner)
	{
		return;
	}

	for (auto& ActiveWeapon : Owner->GetWeapons())
	{
		ActiveWeapon->ActiveCollision(false);
	}
}