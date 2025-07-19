// Made by LSH

#include "GAS/AbilityTask/Jump/AT_Landed.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "Character/Character/BFCharacter.h"

UAT_Landed* UAT_Landed::CreateTask(UGameplayAbility* OwningAbility)
{
	UAT_Landed* Task = NewAbilityTask<UAT_Landed>(OwningAbility);
	return Task;
}

void UAT_Landed::Activate()
{
	Super::Activate();

	ABFCharacter* Owner = Cast<ABFCharacter>(GetAvatarActor());

	Owner->LandedDelegate.AddDynamic(this, &ThisClass::Landed);
}

void UAT_Landed::OnDestroy(bool bInOwnerFinished)
{
	ABFCharacter* Owner = Cast<ABFCharacter>(GetAvatarActor());
	Owner->LandedDelegate.RemoveDynamic(this, &ThisClass::Landed);

	Super::OnDestroy(bInOwnerFinished);
}

void UAT_Landed::Landed(const FHitResult& Hit)
{
	ABFCharacter* Character = Cast<ABFCharacter>(GetAvatarActor());
	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(Character->GetAbilitySystemComponent());
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Jump);

	EndTask();
}