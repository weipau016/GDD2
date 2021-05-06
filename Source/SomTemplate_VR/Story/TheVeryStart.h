// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BaseState.h"

/**
 * 
 */
class SOMTEMPLATE_VR_API TheVeryStart : public BaseState
{
public:
	TheVeryStart();
	~TheVeryStart();

protected:
	void OnEnter();
};
