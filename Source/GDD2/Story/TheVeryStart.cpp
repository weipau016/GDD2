// Fill out your copyright notice in the Description page of Project Settings.

#include "TheVeryStart.h"
#include "../StoryManager.h"
#include "EffectManager.h"

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
	// do not change light here...not initialized yet. change in scene instead
}

void TheVeryStart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	switch (m_sequence_number) {
	case 1:
		
		// wait 5 seconds (for effects to finish)
		if (NextSequenceAfterWait(5)) {
			m_story_manager->GetEffectManager()->SetLightIntensity(12.0f);
			m_startup_sound = false;
			break;
		} 
		
		// play sound once
		if (!m_startup_sound && SecondsSinceSequenceFinished() > 1) {
			m_startup_sound = true;
			PlaySound("machine_startup");
			m_story_manager->GetEffectManager()->SetLightIntensity(12.0f);
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
