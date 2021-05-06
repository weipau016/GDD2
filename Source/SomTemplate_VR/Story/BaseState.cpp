// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "Story/BaseState.h"

BaseState::BaseState()
{
}

BaseState::~BaseState()
{
}

void BaseState::OnEnter()
{
}

void BaseState::OnInput(INPUT_EVENT input)
{
}

void BaseState::OnExit()
{
}

void BaseState::Tick(float DeltaTime)
{
}

void BaseState::Exit(STATE_ID state_id)
{
	m_smc->ChangeToState(state_id);
}
