// Made by LSH

#include "Character/AnimNotify/Transform/BFSetTransform.h"
#include "Character/Character/BFCharacter.h"

void UBFSetTransform::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	ABFCharacter* Owner = Cast<ABFCharacter>(MeshComp->GetOwner());
	if (!Owner)
	{
		return;
	}

	Owner->SetActorLocation(Owner->GetActorLocation() + Owner->GetActorForwardVector() * Distance);
}