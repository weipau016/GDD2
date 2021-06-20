// Fill out your copyright notice in the Description page of Project Settings.


#include "StartingMainProtocol.h"
#include "../StoryManager.h"

StartingMainProtocol::StartingMainProtocol(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 2;
}

StartingMainProtocol::~StartingMainProtocol()
{
}

void StartingMainProtocol::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}

void StartingMainProtocol::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("the-very-start", 2); // TODO: replace with actual follow state
}