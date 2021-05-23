// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API WelcomeAl : public BaseState
{
public:
	WelcomeAl(AStoryManager* story_manager, FString scene_name);
	virtual ~WelcomeAl();

private:
	typedef BaseState Super;

protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Tick(float DeltaTime);
	virtual void OnButtonPressed(const FString& button_name);
	virtual void OnSequenceFinished();
};
