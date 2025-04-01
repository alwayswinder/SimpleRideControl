// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleRideControl/Player/MyPlayerAttributeSet.h"

#include "Net/UnrealNetwork.h"

UMyPlayerAttributeSet::UMyPlayerAttributeSet()
	:CurrentHealth(100.f),MaxHealth(100.f)
{
}

void UMyPlayerAttributeSet::OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyPlayerAttributeSet, CurrentHealth, OldCurrentHealth);
}

void UMyPlayerAttributeSet::OnRep_MaxtHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyPlayerAttributeSet, MaxHealth, OldMaxHealth);
}

void UMyPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyPlayerAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyPlayerAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}