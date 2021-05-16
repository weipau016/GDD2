// Fill out your copyright notice in the Description page of Project Settings.

#include "TheVeryStart.h"

TheVeryStart::TheVeryStart(AStoryManager* story_manager) : BaseState(story_manager)
{
}

TheVeryStart::~TheVeryStart()
{
}

void TheVeryStart::OnEnter()
{
	UE_LOG(LogTemp, Display, TEXT("TheVeryStart: Entered and about to exit again"));
	Exit("WELCOME_AL");
}
