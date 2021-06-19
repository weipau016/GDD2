// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonManager.h"
#include "../StoryManager.h"
#include <stdexcept>


void UButtonManager::RegisterStoryManager(AStoryManager* manager)
{
	_storyManager = manager;
}

void UButtonManager::RegisterButton(AConsoleButton* button)
{
	std::string name = button->GetNameAsString();
	_buttons.insert({ name, button });
	UE_LOG(LogTemp, Log, TEXT("Button '%s' has been registered"), *button->GetName());
}

void UButtonManager::SetButtonActiveState(const std::string& name, bool active)
{
	if (_buttons.find(name) == _buttons.end()) {
		FString nameString(name.c_str());
		UE_LOG(LogTemp, Warning, TEXT("No button '%s' has been registered"), *nameString);
		return;
	}
	_buttons.at(name)->SetActiveState(active);
}

void UButtonManager::SetButtonHiddenState(const std::string& name, bool hidden)
{
	if (_buttons.find(name) == _buttons.end()) {
		FString nameString(name.c_str());
		UE_LOG(LogTemp, Warning, TEXT("No button '%s' has been registered"), *nameString);
		return;
	}
	_buttons.at(name)->SetHiddenState(hidden);
}

void UButtonManager::SetButtonMaterialState(const std::string& name, MaterialState state)
{
	if (_buttons.find(name) == _buttons.end()) {
		FString nameString(name.c_str());
		UE_LOG(LogTemp, Warning, TEXT("No button '%s' has been registered"), *nameString);
		return;
	}
	_buttons.at(name)->SetMaterialState(state);
}

bool UButtonManager::IsButtonActive(const std::string& name) const
{
	return _buttons.at(name)->IsActive();
}

bool UButtonManager::IsButtonHidden(const std::string& name) const
{
	return _buttons.at(name)->IsHidden();
}

void UButtonManager::ButtonPressed(const FString& name)
{
	std::string localName(TCHAR_TO_UTF8(*name));
	if (_buttons.find(localName) == _buttons.end())
		throw std::invalid_argument(std::string("Unknown button name '") + localName + "'");

	if (_storyManager)
		_storyManager->ButtonPressed(name);
	else
		UE_LOG(LogTemp, Warning, TEXT("Button '%s' pressed but no story manager is registered"), *name);
}
