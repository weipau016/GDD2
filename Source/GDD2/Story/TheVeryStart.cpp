// Fill out your copyright notice in the Description page of Project Settings.

#include "TheVeryStart.h"

TheVeryStart::TheVeryStart() : BaseState()
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
