// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "MyAbilityTask_Timeline.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimelineUpdate, float, CurrentValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimelineEnd);
/**
 * 
 */
UCLASS()
class SIMPLERIDECONTROL_API UMyAbilityTask_Timeline : public UAbilityTask
{
	GENERATED_UCLASS_BODY()
public:
	// 声明工厂函数
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(HidePin="OwningAbility", DefaultToSelf="OwningAbility", BlueprintInternalUseOnly = "true"))
	static UMyAbilityTask_Timeline* CreateTimelineTask(
		UGameplayAbility* OwningAbility,
		FName TaskInstanceName,
		FRuntimeFloatCurve CurveFloat, 
		float Duration
	);
       
	// 委托声明
	UPROPERTY(BlueprintAssignable)
	FOnTimelineUpdate OnUpdate;
	
	UPROPERTY(BlueprintAssignable)
	FOnTimelineEnd OnEnd;
	
	virtual void Activate() override;
	virtual void TickTask(float DeltaTime) override;
       
private:
	UPROPERTY()
	FRuntimeFloatCurve CurveFloat;
	
	UPROPERTY()
	float Duration;

	float TimeAcc = 0;
};
