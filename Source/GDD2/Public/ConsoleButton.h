// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConsoleButton.generated.h"


UCLASS()
class GDD2_API AConsoleButton : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	bool _isActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Properties")
	FString _name;

	UFUNCTION(BlueprintNativeEvent)
	void OnButtonStateChange(bool active);

	virtual void OnButtonStateChange_Implementation(bool active);

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

	bool IsActive() const { return _isActive; }

	FString GetName() const { return _name; }

	std::string GetNameAsString() const { return std::string(TCHAR_TO_UTF8(*_name)); }
};
