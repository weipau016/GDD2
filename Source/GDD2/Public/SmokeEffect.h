// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <Math/Vector.h>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SmokeEffect.generated.h"

UENUM(BlueprintType)
enum class SmokeType : uint8
{
	FREEZING		UMETA(Displayname = "Freezing"),
	TOXIN			UMETA(Displayname = "Toxin"),
};

UCLASS()
class GDD2_API ASmokeEffect : public AActor
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Properties")
	SmokeType type = SmokeType::FREEZING;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	float spawnRate = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	float spriteSize = 65.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	float lifeTimeMax = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	float coneAngelMin = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	float coneAngleMax = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FVector coneAxis = FVector(0.0f, 0.0f, -1.0f);

public:
	// Sets default values for this actor's properties
	ASmokeEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Activate(float activeTime);

	virtual void Activate_Implementation(float activeTime);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Deactivate();
	
	virtual void Deactivate_Implementation();
};
