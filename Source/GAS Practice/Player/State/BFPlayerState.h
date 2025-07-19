// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "BFPlayerState.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABFPlayerState();

public:
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	TObjectPtr<class UBFPlayerAttributeSet> GetPlayerAttributeSet() { return PlayerAttributeSet; }

	TObjectPtr<class ABFPlayer> GetBFPlayer() { return BFPlayer; }
	void SetBFPlayer(TObjectPtr<class ABFPlayer> OwnerPlayer);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TObjectPtr<class UBFAbilitySystemComponent> ASC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TObjectPtr<class UBFPlayerAttributeSet> PlayerAttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TObjectPtr<class ABFPlayer> BFPlayer;
};