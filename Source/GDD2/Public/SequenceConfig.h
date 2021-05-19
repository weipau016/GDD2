// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "SequenceConfig.generated.h"
/**
 *
 */
USTRUCT(BlueprintType)
struct GDD2_API FSequenceConfig
{
    GENERATED_USTRUCT_BODY()

        // this is your default constructor which is required for a USTRUCT definition
        FSequenceConfig()
    {
        // initialize things here if desired or required
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        int start_index;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        float duration;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        FString text;
};

