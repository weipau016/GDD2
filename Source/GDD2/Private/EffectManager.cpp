// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectManager.h"
#include "SmokeEffect.h"

void UEffectManager::RegisterSmokeEffect(ASmokeEffect* smokeEffect)
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

void UEffectManager::ActivateFreezingGas_Implementation(float activeTime)
{
}

void UEffectManager::ActivateToxicGas_Implementation(float activeTime)
{
}
