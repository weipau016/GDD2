// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPrejudiceInaction.h"

AiPrejudiceInaction::AiPrejudiceInaction(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 1;
}

AiPrejudiceInaction::~AiPrejudiceInaction()
{
}

void AiPrejudiceInaction::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}

void AiPrejudiceInaction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("starting-main-protocol", 2);
}