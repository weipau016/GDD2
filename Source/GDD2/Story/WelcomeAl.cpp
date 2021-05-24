// Fill out your copyright notice in the Description page of Project Settings.


#include "WelcomeAl.h"
#include "../StoryManager.h"

WelcomeAl::WelcomeAl(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
}

WelcomeAl::~WelcomeAl()
{
}

void WelcomeAl::OnEnter()
{
	Super::OnEnter();
	StartSequence(1);
	// TODO: display AL symbol and color
}

void WelcomeAl::OnExit()
{
	SetButtonState("yes", false);
	SetButtonState("no", false);
}

void WelcomeAl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (SecondsSinceSequenceFinished() > 5) {
		if (m_sequence_number == 6)
		{
			Exit("ai-prejudice-inaction");
		}
		else
		{
			StartSequence(m_sequence_number + 1);
		}
	}
}

void WelcomeAl::OnButtonPressed(const FString& button_name)
{
	Super::OnButtonPressed(button_name);
	if (button_name == "yes")
	{
		Exit("ai-prejudice-yes");
	}
	else if (button_name == "no")
	{
		Exit("ai-prejudice-no");
	}
	else
	{
		// TODO: error?
	}
}

void WelcomeAl::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	if (m_sequence_number == 1) 
	{
		SetButtonState("yes", true);
		SetButtonState("no", true);
	}
}