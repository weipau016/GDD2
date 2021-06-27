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
	int m_last_sequence_number; // set individually in derived ctor

	friend class AStoryManager;

protected:
	float m_time_sequence_finished;
	float m_time_ticked;


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

	void PlaySound(const FString& name);

	// Will exit current state and change to state_id state instead
	void Exit(std::string state_id);

	// Will exit current state and change to last state instead
	void Exit();

	// helper
	// (return true if sequence was changed/exit was called)
	bool ExitAfterWait(const float second_to_wait); // call Exit()
	bool ExitAfterWait(const std::string& state_id, const float second_to_wait);
	bool SequenceAfterWait(const int next_sequence_number, const float second_to_wait);
	bool SequenceOrExitOnLastAfterWait(const int next_sequence_number, const float second_to_wait); 
	bool SequenceOrExitOnLastAfterWait(const int next_sequence_number, const std::string& state_id, const float second_to_wait);
	bool NextSequenceAfterWait(const float second_to_wait);
	bool NextSequenceOrExitOnLastAfterWait(const float second_to_wait);
	bool NextSequenceOrExitOnLastAfterWait(const std::string& state_id, const float second_to_wait);
};
