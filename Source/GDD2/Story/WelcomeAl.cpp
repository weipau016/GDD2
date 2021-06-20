// Fill out your copyright notice in the Description page of Project Settings.


#include "WelcomeAl.h"
#include "../StoryManager.h"

WelcomeAl::WelcomeAl(AStoryManager* story_manager, FString scene_name) : BaseState(story_manager, scene_name)
{
	m_last_sequence_number = 6;
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
	Super::OnExit();
	SetButtonActive("yes", false);
	SetButtonActive("no", false);
	SetButtonLit("yes", false);
	SetButtonLit("no", false);
}

void WelcomeAl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NextSequenceOrExitOnLastAfterWait("ai-prejudice-inaction", 5);
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
}

void WelcomeAl::OnSequenceFinished()
{
	Super::OnSequenceFinished();
	if (m_sequence_number == 1) 
	{
		SetButtonVisible("yes", true);
		SetButtonVisible("no", true);
		SetButtonActive("yes", true);
		SetButtonActive("no", true);
		//SetButtonLit("yes", true);
		//SetButtonLit("no", true);
		FlashButton("yes");
		FlashButton("no");
	}
}