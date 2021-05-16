// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioTrack.generated.h"

USTRUCT(BlueprintType)
struct FAudioTrack
{
    GENERATED_BODY()
    
    // default constructor which is required for a USTRUCT definition
    FAudioTrack()       
    {
        // initialize things here 
        start_timestamp = 0.0f;
    }

    UPROPERTY(BlueprintReadWrite)
        float  start_timestamp;
};

