// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API ReactorRecalibration : public BaseState
{
public:
	ReactorRecalibration(AStoryManager* story_manager, FString scene_name);
	virtual ~ReactorRecalibration();

private:
	typedef BaseState Super;

	std::string m_simon[4];
	FString m_simon_sound[4];
	bool m_simon_in_progress = false;
	int m_simon_order[5] = { };
	
	float m_simon_show_timer = 0.0f;
	bool m_simon_show_any_lit = false;
	int m_simon_show_index = 0;

	int m_last_non_error_sequence = 0;
	float m_last_non_error_sequence_finished = 0.0f;

	int m_simon_input = 0;
	int m_correct_attempts = 0;
	int m_wrong_attempts = 0;

	void StartSimonSays();
	void StopSimonSays();
	void NewSimonPattern();
	void ShowSimonCycle(float DeltaTime);
	void ResetSimonCycle();
	void ShowSimonDimAll();

protected:
	virtual void OnEnter();
	virtual void OnExit();
	virtual void Tick(float DeltaTime);
	virtual void OnButtonPressed(const FString& button_name);
	virtual void OnSequenceFinished();
};
