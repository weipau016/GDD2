// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonManager.h"
#include "../StoryManager.h"
#include "ConsoleButton.h"
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

void UButtonManager::SetButtonState(const std::string& name, bool active)
{
	_buttons.at(name)->SetActiveState(active);
}

bool UButtonManager::IsButtonActive(const std::string& name) const
{
	return _buttons.at(name)->IsActive();
}

void UButtonManager::ButtonPressed(const FString& name)
{
	std::string localName(TCHAR_TO_UTF8(*name));
	if (_buttons.find(localName) == _buttons.end())
		throw std::invalid_argument(std::string("Unknown button name '") + localName + "'");

	if (_storyManager)
		_storyManager->ButtonPressed(localName);
	else
		UE_LOG(LogTemp, Warning, TEXT("Button '%s' pressed but no story manager is registered"), *name);
}
