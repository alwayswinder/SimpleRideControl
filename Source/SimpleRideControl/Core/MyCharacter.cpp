// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "SimpleRideControl/GAS/MyAbilitySystemComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//AbilitySystem
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	// AbilitySystemComponent->SetIsReplicated(true);
	// AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UMyPlayerAttributeSet>(TEXT("AttributeSet"));
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitializeAttributes();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AMyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AMyCharacter::InitializeAttributes()
{
	if(AbilitySystemComponent && AttributeSet)
	{
		//AttributeSet->InitFromMetaDataTable();
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}



