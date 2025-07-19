// Made by LSH

#include "GAS/GameplayTag/BFGameplayTags.h"

FGameplayTag BFGameplayTags::State::Idle;
FGameplayTag BFGameplayTags::State::Move;
FGameplayTag BFGameplayTags::State::Look;
FGameplayTag BFGameplayTags::State::Jump;
FGameplayTag BFGameplayTags::State::Run;
FGameplayTag BFGameplayTags::State::Attack;
FGameplayTag BFGameplayTags::State::Hitted;
FGameplayTag BFGameplayTags::State::Blocked;
FGameplayTag BFGameplayTags::State::LockOn;
FGameplayTag BFGameplayTags::State::Die;

FGameplayTag BFGameplayTags::Attack::CanCombo;
FGameplayTag BFGameplayTags::Attack::Combo1;
FGameplayTag BFGameplayTags::Attack::Combo2;
FGameplayTag BFGameplayTags::Attack::Combo3;
FGameplayTag BFGameplayTags::Attack::Combo4;
FGameplayTag BFGameplayTags::Attack::Combo5;
FGameplayTag BFGameplayTags::Attack::Combo6;
FGameplayTag BFGameplayTags::Attack::Combo7;
FGameplayTag BFGameplayTags::Attack::Combo8;
FGameplayTag BFGameplayTags::Attack::Combo9;
FGameplayTag BFGameplayTags::Attack::Combo10;
FGameplayTag BFGameplayTags::Attack::Combo11;

FGameplayTag BFGameplayTags::Buff::DamageUp;
FGameplayTag BFGameplayTags::Buff::Slow;
FGameplayTag BFGameplayTags::Buff::Fast;

FGameplayTag BFGameplayTags::Data::Speed;

void BFGameplayTags::InitGameplayTags()
{
	// 캐릭터 상태 태그
	State::Idle = FGameplayTag::RequestGameplayTag(FName("Character.State.Idle"));
	State::Move = FGameplayTag::RequestGameplayTag(FName("Character.State.Move"));
	State::Look = FGameplayTag::RequestGameplayTag(FName("Character.State.Look"));
	State::Jump = FGameplayTag::RequestGameplayTag(FName("Character.State.Jump"));
	State::Run = FGameplayTag::RequestGameplayTag(FName("Character.State.Run"));
	State::Attack = FGameplayTag::RequestGameplayTag(FName("Character.State.Attack"));
	State::Hitted = FGameplayTag::RequestGameplayTag(FName("Character.State.Hitted"));
	State::Blocked = FGameplayTag::RequestGameplayTag(FName("Character.State.Blocked"));
	State::LockOn = FGameplayTag::RequestGameplayTag(FName("Character.State.LockOn"));
	State::Die = FGameplayTag::RequestGameplayTag(FName("Character.State.Die"));

	// 캐릭터 공격 콤보 태그
	Attack::CanCombo = FGameplayTag::RequestGameplayTag(FName("Character.Attack.CanCombo"));
	Attack::Combo1 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo1"));
	Attack::Combo2 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo2"));
	Attack::Combo3 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo3"));
	Attack::Combo4 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo4"));
	Attack::Combo5 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo5"));
	Attack::Combo6 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo6"));
	Attack::Combo7 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo7"));
	Attack::Combo8 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo8"));
	Attack::Combo9 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo9"));
	Attack::Combo10 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo10"));
	Attack::Combo11 = FGameplayTag::RequestGameplayTag(FName("Character.Attack.Combo11"));

	// 캐릭터 버프 태그
	Buff::DamageUp = FGameplayTag::RequestGameplayTag(FName("Character.Buff.DamageUp"));
	Buff::Slow = FGameplayTag::RequestGameplayTag(FName("Character.Buff.Slow"));
	Buff::Fast = FGameplayTag::RequestGameplayTag(FName("Character.Buff.Fast"));

	// 데이터 태그
	Data::Speed = FGameplayTag::RequestGameplayTag(FName("Character.Data.Speed"));
}

FGameplayTag BFGameplayTags::FindTagByFName(const FName& FindTag)
{
	// 캐릭터 상태 태그
	if (FindTag == "Idle")
	{
		return State::Idle;
	}
	else if (FindTag == "Move")
	{
		return State::Move;
	}
	else if (FindTag == "Look")
	{
		return State::Look;
	}
	else if (FindTag == "Jump")
	{
		return State::Jump;
	}
	else if (FindTag == "Run")
	{
		return State::Run;
	}
	else if (FindTag == "Attack")
	{
		return State::Attack;
	}
	else if (FindTag == "Hitted")
	{
		return State::Hitted;
	}
	else if (FindTag == "Blocked")
	{
		return State::Blocked;
	}
	else if (FindTag == "LockOn")
	{
		return State::LockOn;
	}
	else if (FindTag == "Die")
	{
		return State::Die;
	}

	// 캐릭터 공격 콤보 태그
	else if (FindTag == "CanCombo")
	{
		return Attack::CanCombo;
	}
	else if (FindTag == "Combo1")
	{
		return Attack::Combo1;
	}
	else if (FindTag == "Combo2")
	{
		return Attack::Combo2;
	}
	else if (FindTag == "Combo3")
	{
		return Attack::Combo3;
	}
	else if (FindTag == "Combo4")
	{
		return Attack::Combo4;
	}
	else if (FindTag == "Combo5")
	{
		return Attack::Combo5;
	}
	else if (FindTag == "Combo6")
	{
		return Attack::Combo6;
	}
	else if (FindTag == "Combo7")
	{
		return Attack::Combo7;
	}
	else if (FindTag == "Combo8")
	{
		return Attack::Combo8;
	}
	else if (FindTag == "Combo9")
	{
		return Attack::Combo9;
	}
	else if (FindTag == "Combo10")
	{
		return Attack::Combo10;
	}
	else if (FindTag == "Combo11")
	{
		return Attack::Combo11;
	}

	// 캐릭터 버프 태그
	else if (FindTag == "DamageUp")
	{
		return Buff::DamageUp;
	}
	else if (FindTag == "Slow")
	{
		return Buff::Slow;
	}
	else if (FindTag == "Fast")
	{
		return Buff::Fast;
	}

	// 데이터 태그
	else if (FindTag == "Speed")
	{
		return Data::Speed;
	}

	return FGameplayTag::EmptyTag;
}