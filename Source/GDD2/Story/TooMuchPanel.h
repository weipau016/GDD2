// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API TooMuchPanel : public BaseState
{
public:
	TooMuchPanel(AStoryManager* story_manager, FString scene_name);
	virtual ~TooMuchPanel();

private:
	typedef BaseState Super;

	int m_actual_sequence = 0;

	bool m_buttons_deactivated = false;

	int m_light = 0;
	bool m_radio = false;

protected:
	virtual void OnEnter();
	virtual void Tick(float DeltaTime);
	virtual void OnButtonPressed(const FString& button_name);

	void Activate(const std::string button_name);
	void Deactivate(const std::string button_name);
};
