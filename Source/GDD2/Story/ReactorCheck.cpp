// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorCheck.h"
#include "../StoryManager.h"

ReactorCheck::ReactorCheck(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 1;
}

ReactorCheck::~ReactorCheck()
{
}

void ReactorCheck::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}
void ReactorCheck::Tick(float DeltaTime)
{
	NextSequenceOrExitOnLastAfterWait("back-again", 5);
}

