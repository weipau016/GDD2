// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPrejudiceYes.h"
#include "../StoryManager.h"

AiPrejudiceYes::AiPrejudiceYes(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 2;
}

AiPrejudiceYes::~AiPrejudiceYes()
{
}

void AiPrejudiceYes::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}

void AiPrejudiceYes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("starting-main-protocol", 2);
}
