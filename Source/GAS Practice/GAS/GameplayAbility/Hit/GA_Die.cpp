// Made by LSH

#include "GAS/GameplayAbility/Hit/GA_Die.h"
#include "GAS/GameplayTag/BFGameplayTags.h"
#include "GAS/AbilitySystemComponent/BFAbilitySystemComponent.h"
#include "Character/Character/BFCharacter.h"

UGA_Die::UGA_Die()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;

	AbilityTags.AddTag(BFGameplayTags::State::Die);
}

void UGA_Die::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	ABFCharacter* Character = Cast<ABFCharacter>(ActorInfo->AvatarActor.Get());

	UBFAbilitySystemComponent* ASC = Cast<UBFAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
	
	ASC->AddUniqueGameplayTag(BFGameplayTags::State::Die);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Attack);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Jump);
	ASC->CancelAbilitiesByTag(BFGameplayTags::State::Run);
}