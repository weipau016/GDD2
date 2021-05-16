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
	WelcomeAl(AStoryManager* story_manager);
	virtual ~WelcomeAl();

protected:
	virtual void OnEnter();
};
