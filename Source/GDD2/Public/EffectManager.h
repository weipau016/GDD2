// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectManager.generated.h"

class ASmokeEffect;

/**
 * 
 */
UCLASS()
class GDD2_API AEffectManager : public AActor
{
	GENERATED_BODY()

private:
	std::vector<ASmokeEffect*> _freezeEffects;
	std::vector<ASmokeEffect*> _toxinEffects;

public:
	// Sets default values for this actor's properties
	AEffectManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void RegisterSmokeEffect(ASmokeEffect* smokeEffect);

	void ActivateFreezingGas(float activeTime);
	void DeactivateFreezingGas();
	void ActivateToxicGas(float activeTime);
	void DeactivateToxicGas();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActivateFadeToBlack();

	virtual void ActivateFadeToBlack_Implementation();
};
