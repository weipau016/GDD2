// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EffectManager.generated.h"

class ASmokeEffect;

/**
 * 
 */
UCLASS(BlueprintType)
class GDD2_API UEffectManager : public UObject
{
	GENERATED_BODY()

private:
	std::vector<ASmokeEffect*> _freezeEffects;
	std::vector<ASmokeEffect*> _toxinEffects;

public:
	UFUNCTION(BlueprintCallable)
	void RegisterSmokeEffect(ASmokeEffect* smokeEffect);

	UFUNCTION(BlueprintNativeEvent, Category = "Effects")
	void ActivateFreezingGas(float activeTime);

	virtual void ActivateFreezingGas_Implementation(float activeTime);

	UFUNCTION(BlueprintNativeEvent, Category = "Effects")
	void ActivateToxicGas(float activeTime);

	virtual void ActivateToxicGas_Implementation(float activeTime);
};
