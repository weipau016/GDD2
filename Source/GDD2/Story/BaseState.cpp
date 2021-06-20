// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseState.h"
#include "../StoryManager.h"
#include "ButtonManager.h"


BaseState::BaseState(AStoryManager* story_manager, FString scene_name) : 
	m_story_manager(story_manager), m_scene_name(scene_name), m_sequence_number(0), m_last_sequence_number(0),
	m_time_sequence_finished(0.0f), m_time_ticked(0.0f)
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
	m_time_ticked += DeltaTime;
}

void BaseState::OnButtonPressed(const FString& button_name)
{
	PlaySound("button_press");
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

void BaseState::SetButtonVisible(const std::string& name, bool visible)
{
	m_story_manager->m_button_manager->SetButtonHiddenState(name, !visible);
}

void BaseState::SetButtonActive(const std::string& name, bool active)
{
	m_story_manager->m_button_manager->SetButtonActiveState(name, active);
}

void BaseState::SetButtonLit(const std::string& name, bool lit)
{
	if (lit) 
	{
		m_story_manager->m_button_manager->SetButtonMaterialState(name, MaterialState::GLOW);
	}
	else 
	{
		m_story_manager->m_button_manager->SetButtonMaterialState(name, MaterialState::OFF);
	}
}

void BaseState::FlashButton(const std::string& name)
{
	m_story_manager->m_button_manager->SetButtonMaterialState(name, MaterialState::FLASH);
}

void BaseState::PlaySound(const FString& name)
{
	m_story_manager->PlaySound(name);
}

void BaseState::Exit(std::string state_id)
{
	m_story_manager->ChangeToState(state_id);
}

void BaseState::Exit()
{
	m_story_manager->ChangeToLastState();
}

// helper

bool BaseState::ExitAfterWait(const float second_to_wait)
{
	if (SecondsSinceSequenceFinished() > second_to_wait)
	{
		Exit();
		return true;
	}
	return false;
}
bool BaseState::ExitAfterWait(const std::string& state_id, const float second_to_wait)
{
	if (SecondsSinceSequenceFinished() > second_to_wait)
	{
		Exit(state_id);
		return true;
	}
	return false;
}
bool BaseState::SequenceAfterWait(const int next_sequence_number, const float second_to_wait)
{
	if (SecondsSinceSequenceFinished() > second_to_wait) 
	{
		StartSequence(next_sequence_number);
		return true;
	}
	return false;
}
bool BaseState::SequenceOrExitOnLastAfterWait(const int next_sequence_number, const float second_to_wait)
{
	if (m_sequence_number == m_last_sequence_number)
	{
		return ExitAfterWait(second_to_wait);
	}
	return SequenceAfterWait(next_sequence_number, second_to_wait);
}
bool BaseState::SequenceOrExitOnLastAfterWait(const int next_sequence_number, const std::string& state_id, const float second_to_wait)
{
	if (m_sequence_number == m_last_sequence_number)
	{
		return ExitAfterWait(state_id, second_to_wait);
	}
	return SequenceAfterWait(next_sequence_number, second_to_wait);
}
bool BaseState::NextSequenceAfterWait(const float second_to_wait)
{
	return SequenceAfterWait(m_sequence_number + 1, second_to_wait);
}
bool BaseState::NextSequenceOrExitOnLastAfterWait(const float second_to_wait)
{
	return SequenceOrExitOnLastAfterWait(m_sequence_number + 1, second_to_wait);
}
bool BaseState::NextSequenceOrExitOnLastAfterWait(const std::string& state_id, const float second_to_wait)
{
	return SequenceOrExitOnLastAfterWait(m_sequence_number + 1, state_id, second_to_wait);
}

