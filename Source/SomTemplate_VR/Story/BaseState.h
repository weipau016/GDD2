// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "StateMachineController.h"

/**
 * 
 */
class SOMTEMPLATE_VR_API BaseState
{
public:
	BaseState();

protected:
	virtual ~BaseState() {}

	virtual void OnEnter();
	virtual void OnInput(INPUT_EVENT input);
	virtual void OnExit();
	virtual void Tick(float DeltaTime);

	void Exit(STATE_ID state_id);

protected:
	AStateMachineController* m_smc;

	friend class StateMachineController;
};
