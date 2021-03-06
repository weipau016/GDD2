// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <unordered_map>
#include <string>

#include "ConsoleButton.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ButtonManager.generated.h"

class AStoryManager;
//class AConsoleButton;

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

	UFUNCTION(BlueprintCallable)
	void RegisterStoryManager(AStoryManager* manager);

	UFUNCTION(BlueprintCallable)
	void RegisterButton(AConsoleButton* button);

	void SetButtonActiveState(const std::string& name, bool active);

	void SetButtonHiddenState(const std::string& name, bool hidden);

	void SetButtonMaterialState(const std::string& name, MaterialState state);

	bool IsButtonActive(const std::string& name) const;

	bool IsButtonHidden(const std::string& name) const;

	UFUNCTION(BlueprintCallable)
	void ButtonPressed(const FString& name);
};
