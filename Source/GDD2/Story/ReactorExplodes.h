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

	float m_timer = 0.0f;
	bool m_ended = false;

protected:
	virtual void OnEnter();
	virtual void Tick(float DeltaTime);
	virtual void OnButtonPressed(const FString& button_name);
	virtual void OnSequenceFinished();

	void End();
};
