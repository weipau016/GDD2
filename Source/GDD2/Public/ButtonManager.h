// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include <string>

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ButtonManager.generated.h"

class AStoryManager;
class AConsoleButton;

/**
 * 
 */
UCLASS(BlueprintType)
class GDD2_API UButtonManager : public UObject
{
	GENERATED_BODY()
	
private:

	AStoryManager* _storyManager;

	std::unordered_map<std::string, AConsoleButton*> _buttons;

public:

	void RegisterStoryManager(AStoryManager& manager);

	UFUNCTION(BlueprintCallable)
	void RegisterButton(AConsoleButton* button);

	void SetButtonState(const std::string& name, bool active);

	bool IsButtonActive(const std::string& name) const;

	void ButtonPressed(const FString& name);
};
