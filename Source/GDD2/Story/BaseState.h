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

	FString m_scene_name;
	int m_sequence_number;

	friend class AStoryManager;

private:
	float m_time_sequence_finished;


protected:
	BaseState(AStoryManager* story_manager, FString scene_name);
	virtual ~BaseState();

	virtual void OnEnter();
	virtual void OnExit();
	virtual void Tick(float DeltaTime);
	virtual void OnButtonPressed(const FString& button_name);
	virtual void OnSequenceFinished();

	void StartSequence(int sequence_number);
	float SecondsSinceSequenceFinished();

	void SetButtonVisible(const std::string& name, bool visible);
	void SetButtonActive(const std::string& name, bool active);
	void SetButtonLit(const std::string& name, bool lit);
	void FlashButton(const std::string& name);

	// Will exit current state and change to state_id state instead
	void Exit(std::string state_id);

	// Will exit current state and change to last state instead
	void Exit();
};
