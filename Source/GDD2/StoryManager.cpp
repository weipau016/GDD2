// Fill out your copyright notice in the Description page of Project Settings.


#include "StoryManager.h"
#include "ButtonManager.h"

#include "Story/BaseState.h"
#include "Story/TheVeryStart.h"
#include "Story/WelcomeAl.h"
#include "Story/AiPrejudiceYes.h"
#include "Story/AiPrejudiceNo.h"
#include "Story/AiPrejudiceInaction.h"
#include "Story/StartingMainProtocol.h"
#include "Story/TooMuchPanel.h"
#include "Story/ReactorRecalibration.h"
#include "Story/ReactorCheck.h"
#include "Story/BackAgain.h"

#include "Story/ReactorExplodes.h"
#include "Story/FrozenAgain.h"
#include "Story/Neurotoxin.h"

#include "Story/InstructionsForRecalibration.h"

// Sets default values
AStoryManager::AStoryManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// normal scenes
	m_states.insert({ "the-very-start",			new TheVeryStart(this, "the-very-start") });
	m_states.insert({ "welcome-al",				new WelcomeAl(this, "welcome-al") });
	m_states.insert({ "ai-prejudice-yes",		new AiPrejudiceYes(this, "ai-prejudice-yes") });
	m_states.insert({ "ai-prejudice-no",		new AiPrejudiceNo(this, "ai-prejudice-no") });
	m_states.insert({ "ai-prejudice-inaction",	new AiPrejudiceInaction(this, "ai-prejudice-inaction") });
	m_states.insert({ "starting-main-protocol",	new StartingMainProtocol(this, "starting-main-protocol") });
	m_states.insert({ "too-much-panel",			new TooMuchPanel(this, "too-much-panel") });
	m_states.insert({ "reactor-recalibration",	new ReactorRecalibration(this, "reactor-recalibration") });
	m_states.insert({ "reactor-check",			new ReactorCheck(this, "reactor-check") });
	m_states.insert({ "back-again",				new BackAgain(this, "back-again") });

	// endings
	m_states.insert({ "reactor-explodes",		new ReactorExplodes(this, "reactor-explodes") });
	m_states.insert({ "frozen-again",			new FrozenAgain(this, "frozen-again") });
	m_states.insert({ "neurotoxin",				new Neurotoxin(this, "neurotoxin") });

	// interruptible scenes
	m_states.insert({ "instructions-for-recalibration",	new InstructionsForRecalibration(this, "instructions-for-recalibration") });

	std::string starting_state_id = "the-very-start";
	m_current_state = m_states[starting_state_id];
	m_history.push(starting_state_id);
}

// Called when the game starts or when spawned
void AStoryManager::BeginPlay()
{
	Super::BeginPlay();
	m_current_state->OnEnter();
}

void AStoryManager::PlaySound_Implementation(const FString& name)
{
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

void AStoryManager::SequenceFinished() 
{
	m_current_state->OnSequenceFinished();
}

void AStoryManager::RegisterButtonManager(UButtonManager* button_manager)
{
	m_button_manager = button_manager;
	UE_LOG(LogTemp, Display, TEXT("Registered ButtonManager!"));
}

void AStoryManager::ButtonPressed(const FString& name)
{
	UE_LOG(LogTemp, Display, TEXT("ButtonPressed: %s"), *name);
	m_current_state->OnButtonPressed(name);
}

void AStoryManager::Skip()
{
	UE_LOG(LogTemp, Display, TEXT("Skipping..."));
	BaseState* current = m_current_state;
	SequenceFinished();
	if (current == m_current_state) {
		m_current_state->m_time_sequence_finished -= 100000;
	}
	PlaySound("button_press");
}
