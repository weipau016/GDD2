// Fill out your copyright notice in the Description page of Project Settings.


#include "InstructionsForRecalibration.h"
#include "../StoryManager.h"

InstructionsForRecalibration::InstructionsForRecalibration(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 2;
}

InstructionsForRecalibration::~InstructionsForRecalibration()
{
}

void InstructionsForRecalibration::OnEnter()
{
	Super::OnEnter();
	if (m_already_visited)
	{
		StartSequence(2);
	}
	else
	{
		StartSequence(1);
	}
	m_already_visited = true;
}
void InstructionsForRecalibration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait(2);
}