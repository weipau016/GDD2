// Fill out your copyright notice in the Description page of Project Settings.


#include "FrozenAgain.h"
#include "../StoryManager.h"
#include "EffectManager.h"

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
	if (!m_fading && SecondsSinceSequenceFinished() > 3)
	{
		m_fading = true;
		m_story_manager->GetEffectManager()->ActivateFadeToWhite(6.0f);
	}
	if (m_fading && SecondsSinceSequenceFinished() > 10)
	{
		ToMainMenu();
	}
}
void FrozenAgain::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	End();
}

void FrozenAgain::End()
{
	if (m_ended) return;
	m_ended = true; 
	m_story_manager->GetEffectManager()->ActivateFreezingGas(0.0f);
	// TODO: play freezing sound
}
