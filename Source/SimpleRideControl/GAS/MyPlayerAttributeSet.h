// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MyPlayerAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSOR(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)

UCLASS()
class SIMPLERIDECONTROL_API UMyPlayerAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UMyPlayerAttributeSet();
	
	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_CurrentHealth)
	FGameplayAttributeData CurrentHealth;
	ATTRIBUTE_ACCESSOR(UMyPlayerAttributeSet, CurrentHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Health", ReplicatedUsing = OnRep_MaxtHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSOR(UMyPlayerAttributeSet, MaxHealth)
protected:
	UFUNCTION()
	virtual void OnRep_CurrentHealth(const FGameplayAttributeData& OldCurrentHealth);

	UFUNCTION()
	virtual void OnRep_MaxtHealth(const FGameplayAttributeData& OldMaxHealth);
	
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
};
