// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
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


public:
	// Sets default values for this actor's properties
	AStoryManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// will be called by the state itself in its Exit() function
	void ChangeToState(std::string state_id);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
