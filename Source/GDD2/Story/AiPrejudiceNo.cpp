// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPrejudiceNo.h"

AiPrejudiceNo::AiPrejudiceNo(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 2;
}

AiPrejudiceNo::~AiPrejudiceNo()
{
}

void AiPrejudiceNo::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}

void AiPrejudiceNo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("starting-main-protocol", 1);
}
