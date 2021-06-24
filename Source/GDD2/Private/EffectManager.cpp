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
}

void AEffectManager::Tick(float DeltaTime)
{
}

void AEffectManager::RegisterSmokeEffect(ASmokeEffect* smokeEffect)
{
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

void AEffectManager::ActivateFadeToBlack_Implementation()
{
}
