// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectManager.h"
#include "SmokeEffect.h"

// Sets default values
AEffectManager::AEffectManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AEffectManager::BeginPlay()
{
	Super::BeginPlay();
}

void AEffectManager::Tick(float DeltaTime)
{
}

void AEffectManager::RegisterSmokeEffect(ASmokeEffect* smokeEffect)
{
	UE_LOG(LogTemp, Log, TEXT("Smoke effect has been registered"));
	switch (smokeEffect->type)
	{
		case SmokeType::FREEZING:
			_freezeEffects.emplace_back(smokeEffect);
			break;
		case SmokeType::TOXIN:
			_toxinEffects.emplace_back(smokeEffect);
			break;
	}
}

void AEffectManager::ActivateFreezingGas(float activeTime)
{
	for (const auto effect : _freezeEffects)
	{
		effect->Activate(activeTime);
	}
}

void AEffectManager::DeactivateFreezingGas()
{
	for (const auto effect : _freezeEffects)
	{
		effect->Deactivate();
	}
}

void AEffectManager::ActivateToxicGas(float activeTime)
{
	for (const auto effect : _toxinEffects)
	{
		effect->Activate(activeTime);
	}
}

void AEffectManager::DeactivateToxicGas()
{
	for (const auto effect : _toxinEffects)
	{
		effect->Deactivate();
	}
}

void AEffectManager::ActivateFadeToBlack_Implementation(float fadeDuration)
{
}

void AEffectManager::ActivateFadeToWhite_Implementation(float fadeDuration)
{
}

void AEffectManager::SetLightIntensity_Implementation(float intensity)
{
	UE_LOG(LogTemp, Log, TEXT("Setting light intensity to %f"), intensity);
}

void AEffectManager::ResetLightIntensity_Implementation()
{
	UE_LOG(LogTemp, Log, TEXT("Resetting light intensity"));
}

void AEffectManager::SetLightColor_Implementation(FLinearColor color)
{
	UE_LOG(LogTemp, Log, TEXT("Setting light color"));
}

void AEffectManager::BlinkLight_Implementation(FLinearColor color, float frequency, float duration, FLinearColor resetColor)
{
	UE_LOG(LogTemp, Log, TEXT("Blinking lights for %fs"), duration);
}
