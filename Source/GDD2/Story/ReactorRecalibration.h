// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API ReactorRecalibration : public BaseState
{
public:
	ReactorRecalibration(AStoryManager* story_manager, FString scene_name);
	virtual ~ReactorRecalibration();

private:
	typedef BaseState Super;
};
