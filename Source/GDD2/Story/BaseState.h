// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <string>

#include "CoreMinimal.h"

class AStoryManager;

/**
 * 
 */
class GDD2_API BaseState
{
protected:
	AStoryManager* m_story_manager;

	friend class AStoryManager;


protected:
	BaseState(AStoryManager* story_manager);
	virtual ~BaseState();

	virtual void OnEnter();
	virtual void OnExit();
	virtual void Tick(float DeltaTime);

	// Will exit current state and change to state_id state instead
	void Exit(std::string state_id);

	// Will exit current state and change to last state instead
	void Exit();
};
