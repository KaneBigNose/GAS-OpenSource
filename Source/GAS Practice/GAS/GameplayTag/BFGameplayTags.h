// Made by LSH

#pragma once

#include "GameplayTagContainer.h"

class PROJECT_BOSSFIGHT_API BFGameplayTags
{
public:
	static void InitGameplayTags();

	static FGameplayTag FindTagByFName(const FName& FindTag);

	struct State
	{
		static FGameplayTag Idle;
		static FGameplayTag Move;
		static FGameplayTag Look;
		static FGameplayTag Jump;
		static FGameplayTag Run;
		static FGameplayTag Attack;
		static FGameplayTag Hitted;
		static FGameplayTag Blocked;
		static FGameplayTag LockOn;
		static FGameplayTag Die;
	};

	struct Attack
	{
		static FGameplayTag CanCombo;
		static FGameplayTag Combo1;
		static FGameplayTag Combo2;
		static FGameplayTag Combo3;
		static FGameplayTag Combo4;
		static FGameplayTag Combo5;
		static FGameplayTag Combo6;
		static FGameplayTag Combo7;
		static FGameplayTag Combo8;
		static FGameplayTag Combo9;
		static FGameplayTag Combo10;
		static FGameplayTag Combo11;
	};

	struct Buff
	{
		static FGameplayTag DamageUp;
		static FGameplayTag Slow;
		static FGameplayTag Fast;
	};

	struct Data
	{
		static FGameplayTag Speed;
	};
};