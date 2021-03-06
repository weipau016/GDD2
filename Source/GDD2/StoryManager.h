// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <stack>
#include <string>

#include "Story/BaseState.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StoryManager.generated.h"

class UButtonManager;
class AEffectManager;

UCLASS()
class GDD2_API AStoryManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "StoryEvents")
	FString GetScene() { return m_current_state->m_scene_name; }

	UFUNCTION(BlueprintCallable, Category = "StoryEvents")
	int GetSequence() { return m_current_state->m_sequence_number; }

	UFUNCTION(BlueprintCallable, Category = "StoryEvents")
	void SequenceFinished();

	UFUNCTION(BlueprintCallable)
	void RegisterButtonManager(UButtonManager* button_manager);

	UFUNCTION(BlueprintCallable)
	void RegisterEffectManager(AEffectManager* effect_manager);

	void ButtonPressed(const FString& name);

	UFUNCTION(BlueprintNativeEvent, Category = "StoryEvents")
	void PlaySound(const FString& name);

	virtual void PlaySound_Implementation(const FString& name);

	UFUNCTION(BlueprintCallable)
	void Skip();

protected:
	BaseState* m_current_state;

	std::map<std::string, BaseState*> m_states;
	
	UButtonManager* m_button_manager;

	AEffectManager* m_effect_manager;

	friend class BaseState;

private:
	std::stack<std::string> m_history;

public:
	int m_karma_al;
	AEffectManager* GetEffectManager() { return m_effect_manager; }

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

	void ToMenu();
};
