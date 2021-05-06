// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "Story/StateMachineController.h"

void AStateMachineController::ChangeToState(STATE_ID state_id)
{
	m_current_state->OnExit();
	m_current_state = m_states[state_id];
	m_current_state->OnEnter();
}

// Sets default values
AStateMachineController::AStateMachineController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStateMachineController::BeginPlay()
{
	Super::BeginPlay();
	m_current_state = m_states[THE_VERY_START];
}

// Called every frame
void AStateMachineController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_current_state->Tick(DeltaTime);
}

void AStateMachineController::Input(INPUT_EVENT input)
{
	m_current_state->OnInput(input);
}

