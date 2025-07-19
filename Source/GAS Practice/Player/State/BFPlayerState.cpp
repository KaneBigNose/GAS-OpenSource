// Made by LSH

#include "Player/State/BFPlayerState.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "GAS/AttributeSet/BFPlayerAttributeSet.h"

ABFPlayerState::ABFPlayerState()
{
	PrimaryActorTick.bCanEverTick = false;

	PlayerAttributeSet = CreateDefaultSubobject<UBFPlayerAttributeSet>(TEXT("PlayerAttributeSet"));

	ASC = CreateDefaultSubobject<UBFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	ASC->AddAttributeSetSubobject(PlayerAttributeSet.Get());
}

UAbilitySystemComponent* ABFPlayerState::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent>(ASC);
}

void ABFPlayerState::SetBFPlayer(TObjectPtr<ABFPlayer> OwnerPlayer)
{
	BFPlayer = OwnerPlayer;
}