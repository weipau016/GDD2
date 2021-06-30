// Fill out your copyright notice in the Description page of Project Settings.


#include "FrozenAgain.h"
#include "../StoryManager.h"

FrozenAgain::FrozenAgain(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
}

FrozenAgain::~FrozenAgain()
{
}

void FrozenAgain::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}
void FrozenAgain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// TODO: activate fade to white after some time
}
void FrozenAgain::OnSequenceFinished()
{
	End();
}

void FrozenAgain::End()
{
	if (m_ended) return;
	m_ended = true;
	// TODO: activate freezer
	// TODO: play freezing sound
}
