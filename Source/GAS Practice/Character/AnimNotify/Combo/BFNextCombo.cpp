// Made by LSH

#include "Character/AnimNotify/Combo/BFNextCombo.h"
#include "Character/Character/BFCharacter.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"

void UBFNextCombo::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	ABFCharacter* Owner = Cast<ABFCharacter>(MeshComp->GetOwner());
	if (!Owner)
	{
		return;
	}

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(Owner->GetAbilitySystemComponent());
	if (!ASC)
	{
		return;
	}

	ASC->RemoveLooseGameplayTag(BFGameplayTags::State::Attack);
	ASC->AddUniqueGameplayTag(BFGameplayTags::Attack::CanCombo);
}