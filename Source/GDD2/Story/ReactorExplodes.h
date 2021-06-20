// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API ReactorExplodes : public BaseState
{
public:
	ReactorExplodes(AStoryManager* story_manager, FString scene_name);
	virtual ~ReactorExplodes();

private:
	typedef BaseState Super;
};
