// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BaseState.h"

#include "CoreMinimal.h"

/**
 * 
 */
class GDD2_API TheVeryStart : public BaseState
{
public:
	TheVeryStart();
	virtual ~TheVeryStart();

protected:
	virtual void OnEnter();
};
