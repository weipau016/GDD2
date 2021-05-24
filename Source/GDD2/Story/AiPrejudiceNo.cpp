// Fill out your copyright notice in the Description page of Project Settings.


#include "AiPrejudiceNo.h"

AiPrejudiceNo::AiPrejudiceNo(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
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
	int last_scene = 2;
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
