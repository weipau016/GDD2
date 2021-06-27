// Fill out your copyright notice in the Description page of Project Settings.


#include "TooMuchPanel.h"
#include "../StoryManager.h"

TooMuchPanel::TooMuchPanel(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 4;
}

TooMuchPanel::~TooMuchPanel()
{
}

void TooMuchPanel::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	// TODO: enable ALL the buttons
}
void TooMuchPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("reactor-recalibration", 5);
	if (!m_buttons_deactivated && m_sequence_number == m_last_sequence_number)
	{
		m_buttons_deactivated = true;
		// TODO: deactivate ALL the buttons again
	}
}
void TooMuchPanel::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	// TODO: switch to appropriate interrupt states
}

