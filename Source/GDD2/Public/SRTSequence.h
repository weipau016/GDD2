// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRTSequence.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct GDD2_API FSRTSequence
{
    GENERATED_USTRUCT_BODY()

    // this is your default constructor which is required for a USTRUCT definition
    FSRTSequence()        
    {
        // initialize things here if desired or required
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
    float start_time;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
    float duration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
    FString text;
};
