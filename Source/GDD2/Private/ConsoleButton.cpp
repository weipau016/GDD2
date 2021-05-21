// Fill out your copyright notice in the Description page of Project Settings.


#include "ConsoleButton.h"

// Sets default values
AConsoleButton::AConsoleButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AConsoleButton::BeginPlay()
{
	Super::BeginPlay();

	// For changes made in editor ???
	SetActiveState(_isActive);
}

// Called every frame
void AConsoleButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConsoleButton::SetActiveState(bool active)
{
	_isActive = active;
	UE_LOG(LogTemp, Log, TEXT("Button '%s' is now %s"), *_name, *FString(active ? "enabled" : "disabled"));
}

