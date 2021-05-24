// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPrejudiceInaction.h"

AiPrejudiceInaction::AiPrejudiceInaction(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
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
	int last_scene = 1;
	if (SecondsSinceSequenceFinished() > 2) {
		if (m_sequence_number == last_scene)
		{
			Exit("the-very-start"); // TODO: replace with actual follow state
		}
		else
		{
			StartSequence(m_sequence_number + 1);
		}
	}
}