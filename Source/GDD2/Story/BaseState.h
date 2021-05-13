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
	BaseState();
	virtual ~BaseState();

	virtual void OnEnter();
	virtual void OnExit();
	virtual void Tick(float DeltaTime);

	void Exit(std::string state_id);

protected:
	AStoryManager* m_story_manager;

	friend class AStoryManager;
};
