// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryManager.h"

// Sets default values
AStoryManager::AStoryManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_states.insert({ "THE_VERY_START",		new TheVeryStart(this) });
	m_states.insert({ "WELCOME_AL",			new WelcomeAl(this) });
}

// Called when the game starts or when spawned
void AStoryManager::BeginPlay()
{
	Super::BeginPlay();
	std::string starting_state_id = "THE_VERY_START";
	m_current_state = m_states[starting_state_id];
	m_history.push(starting_state_id);
	m_current_state->OnEnter();
}

void AStoryManager::ChangeToState(std::string state_id)
{
	m_current_state->OnExit();
	m_current_state = m_states[state_id];

	// only add history if not already last state
	if (m_history.top().compare(state_id) != 0) 
	{
		m_history.push(state_id);
	}

	m_current_state->OnEnter();
}

void AStoryManager::ChangeToLastState()
{
	m_history.pop();
	ChangeToState(m_history.top());
}

// Called every frame
void AStoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_current_state->Tick(DeltaTime);
}

