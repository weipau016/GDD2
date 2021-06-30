// Fill out your copyright notice in the Description page of Project Settings.

#include "TheVeryStart.h"

TheVeryStart::TheVeryStart(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 2;
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
		if (NextSequenceAfterWait(5)) {
			m_startup_sound = false;
			break;
		} 
		
		// play sound once
		if (!m_startup_sound && SecondsSinceSequenceFinished() > 1) {
			m_startup_sound = true;
			PlaySound("machine_startup");
		}
		break;
	case 2:
		
		// wait another second
		if (ExitAfterWait("welcome-al", 1)) {
			break;
		} 
		
		// play sound once
		if (!m_startup_sound && SecondsSinceSequenceFinished() > 0) {
			m_startup_sound = true;
			PlaySound("decision_button_press_sound");
			PlaySound("ambient");
		}
		break;
	}
}
