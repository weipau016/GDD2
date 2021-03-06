// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsoleButton.h"
#include "Misc/AssertionMacros.h"

// Sets default values
AConsoleButton::AConsoleButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AConsoleButton::OnButtonActiveStateChange_Implementation(bool active)
{
	UE_LOG(LogTemp, Log, TEXT("Button '%s' is now %s"), *name, *FString(active ? "enabled" : "disabled"));
}

void AConsoleButton::OnButtonHiddenStateChange_Implementation(bool hidden)
{
	UE_LOG(LogTemp, Log, TEXT("Button '%s' is now %s"), *name, *FString(hidden ? "hidden" : "visible"));
}

void AConsoleButton::OnButtonMaterialStateChange_Implementation(MaterialState state)
{
	UE_LOG(LogTemp, Log, TEXT("Button '%s' material state changed"), *name);
}

// Called when the game starts or when spawned
void AConsoleButton::BeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("Button '%s' begin play"), *name);

	// For changes made in editor ???
	//SetActiveState(isActive);
	//SetHiddenState(isHidden);
	OnButtonActiveStateChange(isActive);
	OnButtonHiddenStateChange(isHidden);

	Super::BeginPlay();
}

// Called every frame
void AConsoleButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConsoleButton::SetActiveState(bool active)
{
	isActive = active;
	OnButtonActiveStateChange(active);
}

void AConsoleButton::SetHiddenState(bool hidden)
{
	isHidden = hidden;
	OnButtonHiddenStateChange(hidden);
}

void AConsoleButton::SetMaterialState(MaterialState state)
{
	OnButtonMaterialStateChange(state);
}

