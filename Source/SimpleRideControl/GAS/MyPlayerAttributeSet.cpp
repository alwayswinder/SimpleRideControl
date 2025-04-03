// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerAttributeSet.h"

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

void UMyPlayerAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if(Attribute == GetCurrentHealthAttribute())
	{
		// Clamp the new value to be between 0 and MaxHealth
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if (Attribute == GetMaxHealthAttribute())
	{
		// Clamp CurrentHealth to be less than or equal to MaxHealth
		if (CurrentHealth.GetCurrentValue() > NewValue)
		{
			SetCurrentHealth(NewValue);
		}
	}
}

void UMyPlayerAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyPlayerAttributeSet, CurrentHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyPlayerAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
}
