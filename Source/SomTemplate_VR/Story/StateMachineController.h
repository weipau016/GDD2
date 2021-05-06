// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include <map>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StateMachineController.generated.h"

#include "BaseState.h"
#include "TheVeryStart.h"
#include "WelcomeAl.h"

UENUM()
enum STATE_ID {
	THE_VERY_START,
	WELCOME_AL,
};

USTRUCT()
struct INPUT_EVENT {
	int button_clicked;
};

UCLASS()
class SOMTEMPLATE_VR_API AStateMachineController : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// will be called by the state itself in its Exit() function
	void ChangeToState(STATE_ID state_id);

public:	
	// Sets default values for this actor's properties
	AStateMachineController();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// call on player input (like button press or similar)
	void Input(INPUT_EVENT input);

protected:
	BaseState* m_current_state;

	std::map<STATE_ID, BaseState*> m_states = {
		{THE_VERY_START, new TheVeryStart()},
		{WELCOME_AL, new WelcomeAl()},
	};

	friend class BaseState;
};
