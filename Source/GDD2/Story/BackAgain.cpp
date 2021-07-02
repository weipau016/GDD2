// Fill out your copyright notice in the Description page of Project Settings.


#include "BackAgain.h"
#include "../StoryManager.h"

BackAgain::BackAgain(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 4;
}

BackAgain::~BackAgain()
{
}

void BackAgain::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	float karma = m_story_manager->m_karma_al;
	m_good = karma >= 10;
	m_bad = karma <= -40;
	UE_LOG(LogTemp, Display, TEXT("Karma value: %f"), karma);
}
void BackAgain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_good)
	{
		if (m_sequence_number == 1)
		{
			SequenceAfterWait(3, 4);
		}
		else
		{
			NextSequenceOrExitOnLastAfterWait("frozen-again", 3);
		}
	}
	else if (m_bad)
	{
		ExitAfterWait("neurotoxin", 3);
	}
	else
	{
		if (m_sequence_number == 1)
		{
			NextSequenceAfterWait(4);
		}
		else
		{
			ExitAfterWait("frozen-again", 3);
		}
	}
}