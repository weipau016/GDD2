// Fill out your copyright notice in the Description page of Project Settings.


#include "TooMuchPanel.h"
#include "../StoryManager.h"
#include "EffectManager.h"

TooMuchPanel::TooMuchPanel(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 4;
}

TooMuchPanel::~TooMuchPanel()
{
}

void TooMuchPanel::OnEnter()
{
	Super::OnEnter();
	m_actual_sequence++;
	StartSequence(m_actual_sequence);
	Activate("simon-1");
	Activate("simon-2");
	Activate("simon-3");
	Activate("simon-4");
	Activate("radio");
	Activate("light");
	Activate("fun-explosion");
	Activate("instructions");
	Activate("yes");
	Activate("no");
}
void TooMuchPanel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (NextSequenceOrExitOnLastAfterWait("reactor-recalibration", 5))
	{
		m_actual_sequence++;
	}
	if (!m_buttons_deactivated && m_sequence_number == m_last_sequence_number)
	{
		m_buttons_deactivated = true;
		SetButtonActive("simon-1", false);
		SetButtonActive("simon-2", false);
		SetButtonActive("simon-3", false);
		SetButtonActive("simon-4", false);
		Deactivate("radio");
		Deactivate("light");
		Deactivate("fun-explosion");
		SetButtonActive("instructions", false);
		SetButtonActive("yes", false);
		SetButtonActive("no", false);
		m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(1.0f, 1.0f, 1.0f));
	}
}
void TooMuchPanel::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	m_story_manager->m_karma_al -= 10;
	PlaySound("button_press");
	if (button_name.Compare("radio") == 0)
	{
		if (!m_radio)
		{
			m_radio = true;
			SetButtonActive("radio", false);
			PlaySound("dark_radio");
		}
	}
	else if (button_name.Compare("light") == 0)
	{
		switch (m_light)
		{
		case 0:
			m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(0.0f, 1.0f, 0.0f));
			break;
		case 1:
			m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(0.0f, 0.0f, 1.0f));
			break;
		case 2:
			m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(0.5f, 1.0f, 0.0f));
			break;
		case 3:
			m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(0.0f, 0.5f, 1.0f));
			break;
		}
		m_light = (m_light + 1) % 4;
	}
	else if (button_name.Compare("instructions") == 0)
	{
		Exit("instructions-for-recalibration");
	}
}

void TooMuchPanel::Activate(const std::string button_name)
{
	SetButtonActive(button_name, true);
	SetButtonVisible(button_name, true);
}
void TooMuchPanel::Deactivate(const std::string button_name)
{
	SetButtonActive(button_name, false);
	SetButtonVisible(button_name, false);
}
