// Fill out your copyright notice in the Description page of Project Settings.


#include "Neurotoxin.h"
#include "../StoryManager.h"
#include "EffectManager.h"

Neurotoxin::Neurotoxin(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_sequence_number = 2;
}

Neurotoxin::~Neurotoxin()
{
}

void Neurotoxin::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}
void Neurotoxin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_sequence_number == 1)
	{
		NextSequenceAfterWait(2);
	}
	else
	{
		if (!m_fading && SecondsSinceSequenceFinished() > 3)
		{
			m_fading = true;
			m_story_manager->GetEffectManager()->ActivateFadeToBlack(6.0f);
		}
		if (m_fading && SecondsSinceSequenceFinished() > 10)
		{
			ToMainMenu();
		}
	}
}
void Neurotoxin::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	if (m_sequence_number == 2)
	{
		End();
	}
}

void Neurotoxin::End()
{
	if (m_ended) return;
	m_ended = true;
	m_story_manager->GetEffectManager()->ActivateToxicGas(0.0f);
	// TODO: sound
}
