// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "BFActiveCollision.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UBFActiveCollision : public UAnimNotifyState
{
	GENERATED_BODY()
	
protected:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

protected:
	UPROPERTY(EditAnywhere, Category = "GAS")
	struct FGameplayTag CurrentComboTag;

	UPROPERTY(EditAnywhere, Category = "GAS")
	float DamageScale = 1.0f;
};