// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorExplodes.h"
#include "../StoryManager.h"
#include "EffectManager.h"

ReactorExplodes::ReactorExplodes(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 1;
	m_simon[0] = "simon-1";
	m_simon[1] = "simon-2";
	m_simon[2] = "simon-3";
	m_simon[3] = "simon-4";
}

ReactorExplodes::~ReactorExplodes()
{
}

void ReactorExplodes::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
}
void ReactorExplodes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_timer -= DeltaTime;
	if (m_timer <= 0.0f)
	{
		if (m_ended)
		{
			ToMainMenu();
		}
		else
		{
			PlaySound("alert");
			m_timer = 2.0f;
			for (int i = 0; i < 4; i++)
			{
				if (m_buttons == 2)
				{
					SetButtonActive(m_simon[i], true);
				}
				SetButtonLit(m_simon[i], m_buttons % 2 == 1);
			}
			m_buttons++;
		}
	}	
}
void ReactorExplodes::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	End();
}
void ReactorExplodes::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	End();
}

void ReactorExplodes::End()
{
	if (m_ended) return;
	m_ended = true;
	StartSequence(0);
	PlaySound("explosion");
	m_story_manager->GetEffectManager()->ActivateFadeToWhite(0.6f);
	m_timer = 7.0f;
	for (int i = 0; i < 4; i++)
	{
		SetButtonActive(m_simon[i], false);
		SetButtonLit(m_simon[i], false);
	}
}
