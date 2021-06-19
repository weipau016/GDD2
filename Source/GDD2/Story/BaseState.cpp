// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseState.h"
#include "../StoryManager.h"
#include "ButtonManager.h"


BaseState::BaseState(AStoryManager* story_manager, FString scene_name) : 
	m_story_manager(story_manager), m_scene_name(scene_name), m_sequence_number(0)
{
}

BaseState::~BaseState()
{
}

void BaseState::OnEnter()
{
	UE_LOG(LogTemp, Display, TEXT("Entered State: %s"), *m_scene_name);
}

void BaseState::OnExit()
{
}

void BaseState::Tick(float DeltaTime)
{
}

void BaseState::OnButtonPressed(const FString& button_name)
{
}

void BaseState::OnSequenceFinished()
{
	m_time_sequence_finished = m_story_manager->GetGameTimeSinceCreation();
}

void BaseState::StartSequence(int sequence_number)
{
	m_time_sequence_finished = 0.0f;
	m_sequence_number = sequence_number;
}

float BaseState::SecondsSinceSequenceFinished() 
{
	return m_time_sequence_finished != 0.0f ?
		m_story_manager->GetGameTimeSinceCreation() - m_time_sequence_finished : 0.0f;
}

void BaseState::SetButtonState(const std::string& name, bool active)
{
	m_story_manager->m_button_manager->SetButtonActiveState(name, active);
}

void BaseState::Exit(std::string state_id)
{
	m_story_manager->ChangeToState(state_id);
}

void BaseState::Exit()
{
	m_story_manager->ChangeToLastState();
}

