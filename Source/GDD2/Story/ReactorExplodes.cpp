// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorExplodes.h"
#include "../StoryManager.h"

ReactorExplodes::ReactorExplodes(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
}

ReactorExplodes::~ReactorExplodes()
{
}

void ReactorExplodes::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	// TODO: enable simon buttons again?
}
void ReactorExplodes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_timer -= DeltaTime;
	if (!m_ended && m_timer <= 0.0f)
	{
		PlaySound("alert");
		m_timer = 2.0f;
	}
}
void ReactorExplodes::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	End();
}
void ReactorExplodes::OnSequenceFinished()
{
	End();
}

void ReactorExplodes::End()
{
	if (m_ended) return;
	m_ended = true;
	StartSequence(0);
	PlaySound("explosion");
	// TODO: fade to white?
	// TODO: go to menu after effect/fade
}
