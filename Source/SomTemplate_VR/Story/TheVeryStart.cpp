// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "Story/TheVeryStart.h"

TheVeryStart::TheVeryStart()
{
}

TheVeryStart::~TheVeryStart()
{
}

void TheVeryStart::OnEnter()
{
	UE_LOG(LogTemp, Display, TEXT("TheVeryStart: Entered and about to exit again"));
	Exit(WELCOME_AL);
}
