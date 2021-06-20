// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API Neurotoxin : public BaseState
{
public:
	Neurotoxin(AStoryManager* story_manager, FString scene_name);
	virtual ~Neurotoxin();

private:
	typedef BaseState Super;
};
