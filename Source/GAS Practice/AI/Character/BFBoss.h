// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Character/Character/BFCharacter.h"
#include "BFBoss.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API ABFBoss : public ABFCharacter
{
	GENERATED_BODY()
	
public:
	ABFBoss(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void PossessedBy(AController* NewController) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BFCharacter|GAS")
	TObjectPtr<class UBFBossAttributeSet> BossAttributeSet;
};