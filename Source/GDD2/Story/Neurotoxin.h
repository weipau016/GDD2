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

	bool m_ended = false;
	bool m_fading = false;

protected:
	virtual void OnEnter();
	virtual void Tick(float DeltaTime);
	virtual void OnSequenceFinished();

	void End();
};
