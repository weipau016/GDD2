// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SRTSequence.h"
#include "AudioSequence.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct GDD2_API FAudioSequence 
{
    GENERATED_USTRUCT_BODY()

        FAudioSequence()
    {

    }

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        bool is_playing;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        float last_played_timestamp;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        class USoundBase* sound_track;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Config")
        TArray<FSRTSequence> srt_sequences;

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
        int32 current_srt_index;


};
