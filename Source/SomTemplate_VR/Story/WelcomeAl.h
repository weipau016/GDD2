// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseState.h"

/**
 * 
 */
class SOMTEMPLATE_VR_API WelcomeAl : public BaseState
{
public:
	WelcomeAl();
	~WelcomeAl();

protected:
	void OnEnter();
};
