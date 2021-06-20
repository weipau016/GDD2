// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API InstructionsForRecalibration : public BaseState
{
public:
	InstructionsForRecalibration(AStoryManager* story_manager, FString scene_name);
	virtual ~InstructionsForRecalibration();

private:
	typedef BaseState Super;
};
