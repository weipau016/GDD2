// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioTrack.h"
#include "SceneConfig.generated.h"


UCLASS()
class SOMTEMPLATE_VR_API ASceneConfig : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASceneConfig();

	FAudioTrack audio_track;

	UFUNCTION(BlueprintCallable, Category = "AudioInit")
	void initializeAudioTracks(TArray<FAudioTrack>& audio_tracks);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
