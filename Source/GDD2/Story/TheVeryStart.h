// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API TheVeryStart : public BaseState
{
public:
	TheVeryStart(AStoryManager* story_manager, FString scene_name);
	virtual ~TheVeryStart();

private:
	typedef BaseState Super;

protected:
	virtual void OnEnter();
	virtual void Tick(float DeltaTime);
};
