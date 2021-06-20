// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API BackAgain : public BaseState
{
public:
	BackAgain(AStoryManager* story_manager, FString scene_name);
	virtual ~BackAgain();

private:
	typedef BaseState Super;
};
