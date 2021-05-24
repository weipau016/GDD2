// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API AiPrejudiceInaction : public BaseState
{
public:
	AiPrejudiceInaction(AStoryManager* story_manager, FString scene_name);
	~AiPrejudiceInaction();

private:
	typedef BaseState Super;

protected:
	virtual void OnEnter();
	virtual void Tick(float DeltaTime);
};
