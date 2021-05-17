// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <stack>
#include <string>

#include "Story/BaseState.h"
#include "Story/TheVeryStart.h"
#include "Story/WelcomeAl.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StoryManager.generated.h"

UCLASS()
class GDD2_API AStoryManager : public AActor
{
	GENERATED_BODY()

protected:
	BaseState* m_current_state;

	std::map<std::string, BaseState*> m_states;

	friend class BaseState;

private:
	std::stack<std::string> m_history;

public:
	// Sets default values for this actor's properties
	AStoryManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// change current state to indicated
	// will be called by the state itself in its Exit() function
	void ChangeToState(std::string state_id);

	// change to last state in history
	void ChangeToLastState();
};