// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseState.h"
#include "../StoryManager.h"

BaseState::BaseState(AStoryManager* story_manager) : m_story_manager(story_manager)
{
}

BaseState::~BaseState()
{
}

void BaseState::OnEnter()
{
}

void BaseState::OnExit()
{
}

void BaseState::Tick(float DeltaTime)
{
}

void BaseState::Exit(std::string state_id)
{
	m_story_manager->ChangeToState(state_id);
}

void BaseState::Exit()
{
	m_story_manager->ChangeToLastState();
}

