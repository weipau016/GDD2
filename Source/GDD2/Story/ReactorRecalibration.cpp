// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorRecalibration.h"
#include "../StoryManager.h"
#include "EffectManager.h"

ReactorRecalibration::ReactorRecalibration(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 9; // 10 and 11 are wrong attempts
	m_simon[0] = "simon-1";
	m_simon[1] = "simon-2";
	m_simon[2] = "simon-3";
	m_simon[3] = "simon-4";
	m_simon_sound[0] = "simon_says_1";
	m_simon_sound[1] = "simon_says_2";
	m_simon_sound[2] = "simon_says_3";
	m_simon_sound[3] = "simon_says_4";
}

ReactorRecalibration::~ReactorRecalibration()
{
}

void ReactorRecalibration::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	for (int i = 0; i < 4; i++)
	{
		SetButtonVisible(m_simon[i], true);
		SetButtonActive(m_simon[i], false);
	}
}
void ReactorRecalibration::OnExit()
{
	Super::OnExit();
	StopSimonSays();
	m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(1.0f, 1.0f, 1.0f));
	// TODO: deactivate buttons
}
void ReactorRecalibration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_simon_in_progress)
	{
		ShowSimonCycle(DeltaTime);
	}

	switch (m_sequence_number)
	{
	case 1:
		if (NextSequenceAfterWait(7))
		{
			// TODO: deactivate and dim instruction button
		}
		break;
	case 2:
		NextSequenceAfterWait(3);
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		if (m_last_non_error_sequence == m_last_sequence_number)
		{
			ExitAfterWait("reactor-explodes", 30);
		}
		else
		{
			SequenceAfterWait(m_last_non_error_sequence + 1, 10);
		}
		break;
	}
}
void ReactorRecalibration::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	// TODO: if (m_sequence_number == 1 && button_name == "name_of_instruction_button") exit to instruction sequence

	for (int i = 0; i < 4; i++)
	{
		if (button_name.Compare(m_simon[i].c_str()) == 0) 
		{
			// simon button was pressed
			ShowSimonDimAll();
			m_simon_show_timer = 1.0f;
			m_simon_show_index = -1;
			m_simon_show_any_lit = true;
			SetButtonLit(m_simon[i], true);
			PlaySound(m_simon_sound[i]);

			if (m_simon_order[m_simon_input] == i)
			{
				// correct input
				m_simon_input++;
				if (m_simon_input > 2 + m_correct_attempts)
				{
					// completed the whole round correctly
					m_correct_attempts++;
					m_simon_input = 0;
					PlaySound("decision_button_press_sound");
					if (m_correct_attempts > 2)
					{
						Exit("reactor-check");
					}
					// TODO: potentially new simon pattern?
				}
			}
			else
			{
				// mistake!
				PlaySound("button_disappear");
				m_wrong_attempts++;
				StopSimonSays();
				if (m_wrong_attempts > 2)
				{
					Exit("reactor-explodes");
				}
				else
				{
					StartSequence(9 + m_wrong_attempts);
				}
			}
			break;
		}
	}
}
void ReactorRecalibration::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	switch (m_sequence_number)
	{
	case 1:
		// TODO: activate and light up instruction button
		break;
	case 2:
		m_story_manager->GetEffectManager()->SetLightColor(FLinearColor(1.0f, 0.34f, 0.0f));
		break;
	case 3:
		NewSimonPattern();
		StartSimonSays();
	case 4:
	case 5:	
	case 6:
	case 7:
	case 8:
	case 9:
		m_last_non_error_sequence_finished = m_time_sequence_finished;
		m_last_non_error_sequence = m_sequence_number;
		break;
	case 10:
	case 11:
		m_time_sequence_finished = m_last_non_error_sequence_finished;
		StartSimonSays();
		break;
	}
}

void ReactorRecalibration::StartSimonSays()
{
	for (int i = 0; i < 4; i++)
	{
		SetButtonActive(m_simon[i], true);
	}
	ResetSimonCycle();
	m_simon_in_progress = true;
}
void ReactorRecalibration::StopSimonSays()
{
	for (int i = 0; i < 4; i++)
	{
		SetButtonActive(m_simon[i], false);
	}
	ResetSimonCycle();
	m_simon_in_progress = false;
}

void ReactorRecalibration::NewSimonPattern()
{
	// guaranteed to be random every time
	m_simon_order[0] = 0;
	m_simon_order[1] = 3;
	m_simon_order[2] = 1;
	m_simon_order[3] = 2;
	m_simon_order[4] = 1;
}

void ReactorRecalibration::ShowSimonCycle(float DeltaTime)
{
	m_simon_show_timer -= DeltaTime;
	if (m_simon_show_timer <= 0.0f)
	{
		if (m_simon_show_any_lit)
		{
			// a button is lit, turn it of and wait
			ShowSimonDimAll();
			m_simon_show_index++;
			if (m_simon_show_index < 3 + m_correct_attempts)
			{
				// still in same cycle, wait for shorter time
				m_simon_show_timer = 0.8f;
			}
			else
			{
				// done with cycle, wait for longer
				m_simon_show_index = 0;
				m_simon_show_timer = 4.0f;
			}
		}
		else
		{
			// all buttons are unlit, show next in cycle
			int button_index = m_simon_order[m_simon_show_index];
			SetButtonLit(m_simon[button_index], true);
			PlaySound(m_simon_sound[button_index]);
			m_simon_show_timer = 0.5f;
		}
		m_simon_show_any_lit = !m_simon_show_any_lit;
	}
}

void ReactorRecalibration::ResetSimonCycle()
{
	ShowSimonDimAll();
	m_simon_show_timer = 0.0f;
	m_simon_show_index = 0;
	m_simon_show_any_lit = false;
	m_simon_input = 0;
}

void ReactorRecalibration::ShowSimonDimAll()
{
	for (int i = 0; i < 4; i++)
	{
		SetButtonLit(m_simon[i], false);
	}
}
