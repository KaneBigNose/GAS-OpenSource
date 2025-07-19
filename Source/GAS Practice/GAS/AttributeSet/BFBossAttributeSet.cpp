// Made by LSH

#include "GAS/AttributeSet/BFBossAttributeSet.h"

UBFBossAttributeSet::UBFBossAttributeSet(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	InitMaxHP(1000.0f);
	InitCurrentHP(1000.0f);

	InitWalkSpeed(300.0f);
	InitRunSpeed(600.0f);

	InitDamage(100.0f);
	InitArmor(10.0f);
}