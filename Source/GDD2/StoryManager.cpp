// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryManager.h"

// Sets default values
AStoryManager::AStoryManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_states.insert({ "THE_VERY_START",		new TheVeryStart() });
	m_states.insert({ "WELCOME_AL",			new WelcomeAl() });
}

// Called when the game starts or when spawned
void AStoryManager::BeginPlay()
{
	Super::BeginPlay();
	m_current_state = m_states["THE_VERY_START"];
	m_current_state->m_story_manager = this;
	m_current_state->OnEnter();
}

void AStoryManager::ChangeToState(std::string state_id)
{
	m_current_state->OnExit();
	m_current_state = m_states[state_id];
	m_current_state->m_story_manager = this;
	m_current_state->OnEnter();
}

// Called every frame
void AStoryManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	m_current_state->Tick(DeltaTime);
}

