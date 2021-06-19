// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConsoleButton.generated.h"

UENUM(BlueprintType)
enum class MaterialState : uint8
{
	OFF			UMETA(Displayname = "Off"),
	GLOW		UMETA(Displayname = "Glow"),
	FLASH		UMETA(Displayname = "Flash"),
};

UCLASS()
class GDD2_API AConsoleButton : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	bool isActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	bool isHidden;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FString name;

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonActiveStateChange(bool active);

	virtual void OnButtonActiveStateChange_Implementation(bool active);

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonHiddenStateChange(bool hidden);

	virtual void OnButtonHiddenStateChange_Implementation(bool hidden);

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonMaterialStateChange(MaterialState state);

	virtual void OnButtonMaterialStateChange_Implementation(MaterialState state);

public:	
	// Sets default values for this actor's properties
	AConsoleButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetActiveState(bool active);

	UFUNCTION(BlueprintCallable)
	void SetHiddenState(bool hidden);

	UFUNCTION(BlueprintCallable)
	void SetMaterialState(MaterialState state);

	bool IsActive() const { return isActive; }

	bool IsHidden() const { return isHidden; }

	FString GetName() const { return name; }

	std::string GetNameAsString() const { return std::string(TCHAR_TO_UTF8(*name)); }
};
