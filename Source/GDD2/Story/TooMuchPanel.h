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
};
