// Fill out your copyright notice in the Description page of Project Settings.

#include "TheVeryStart.h"

TheVeryStart::TheVeryStart(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
}

TheVeryStart::~TheVeryStart()
{
}

void TheVeryStart::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	// TODO: turn on light (should be dimmed at start)
	// TODO: enable startup sounds and light effects
}

void TheVeryStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	switch (m_sequence_number) {
	case 1:
		// wait 5 seconds (for effects to finish)
		if (SecondsSinceSequenceFinished() > 5) {
			StartSequence(2);
		}
		break;
	case 2:
		// wait another second
		if (SecondsSinceSequenceFinished() > 1) {
			Exit("welcome-al");
		}
		break;
	}
}
