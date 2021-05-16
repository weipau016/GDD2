// Copyright (c) 2014-2019 Sombusta, All Rights Reserved.


#include "SceneConfig.h"
#include <fstream>

// Sets default values
ASceneConfig::ASceneConfig()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



void ASceneConfig::initializeAudioTracks(TArray<FAudioTrack>& audio_tracks)
{
	audio_tracks.Init(FAudioTrack(), 10);

}

// Called when the game starts or when spawned
void ASceneConfig::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASceneConfig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

