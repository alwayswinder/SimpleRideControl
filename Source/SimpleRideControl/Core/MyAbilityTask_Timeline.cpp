// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAbilityTask_Timeline.h"

UMyAbilityTask_Timeline::UMyAbilityTask_Timeline(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	bTickingTask = true;
	bSimulatedTask = true;
}
UMyAbilityTask_Timeline* UMyAbilityTask_Timeline::CreateTimelineTask(UGameplayAbility* OwningAbility,
                                                                     FName TaskInstanceName, FRuntimeFloatCurve CurveFloat, float Duration)
{
	UMyAbilityTask_Timeline* MyObj = NewAbilityTask<UMyAbilityTask_Timeline>(OwningAbility, TaskInstanceName);
	MyObj->CurveFloat = CurveFloat;
	MyObj->Duration = Duration;
	MyObj->TimeAcc = 0;
	return MyObj;
}

void UMyAbilityTask_Timeline::Activate()
{
	Super::Activate();
	if (!CurveFloat.GetRichCurveConst())
	{
		EndTask();
	}
}

void UMyAbilityTask_Timeline::TickTask(float DeltaTime)
{
	if (TimeAcc <= Duration)
	{
		const float CurrentValue = CurveFloat.GetRichCurve()->Eval(TimeAcc);
		OnUpdate.Broadcast(CurrentValue);
		TimeAcc += DeltaTime;
	}
	else
	{
		OnEnd.Broadcast();
		EndTask();
	}
}