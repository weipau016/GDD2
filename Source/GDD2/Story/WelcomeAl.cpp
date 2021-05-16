// Fill out your copyright notice in the Description page of Project Settings.


#include "WelcomeAl.h"

WelcomeAl::WelcomeAl() : BaseState()
{
}

WelcomeAl::~WelcomeAl()
{
}

void WelcomeAl::OnEnter()
{
	UE_LOG(LogTemp, Display, TEXT("WelcomeAl: Entered"));
}
