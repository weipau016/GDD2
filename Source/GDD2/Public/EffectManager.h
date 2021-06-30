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
	void ActivateFadeToBlack(float fadeDuration);
	virtual void ActivateFadeToBlack_Implementation(float fadeDuration);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ActivateFadeToWhite(float fadeDuration);
	virtual void ActivateFadeToWhite_Implementation(float fadeDuration);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetLightIntensity(float intensity);
	virtual void SetLightIntensity_Implementation(float intensity);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ResetLightIntensity();
	virtual void ResetLightIntensity_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetLightColor(FLinearColor color);
	virtual void SetLightColor_Implementation(FLinearColor color);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void BlinkLight(FLinearColor color, float frequency, float duration, FLinearColor resetColor);
	virtual void BlinkLight_Implementation(FLinearColor color, float frequency, float duration, FLinearColor resetColor);
};
