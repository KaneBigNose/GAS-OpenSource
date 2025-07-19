// Made by LSH

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AT_Landed.generated.h"

UCLASS()
class PROJECT_BOSSFIGHT_API UAT_Landed : public UAbilityTask
{
	GENERATED_BODY()

public:
	static UAT_Landed* CreateTask(UGameplayAbility* OwningAbility);
	
protected:
	virtual void Activate() override;

	virtual void OnDestroy(bool bInOwnerFinished) override;

protected:
	UFUNCTION()
	void Landed(const FHitResult& Hit);
};