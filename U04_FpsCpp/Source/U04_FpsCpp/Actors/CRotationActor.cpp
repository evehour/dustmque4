// Fill out your copyright notice in the Description page of Project Settings.

#include "CRotationActor.h"


// Sets default values
ACRotationActor::ACRotationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	YawValue = PitchValue = RollValue = 0.0f;
}

// Called when the game starts or when spawned
void ACRotationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACRotationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator rotation = FRotator(PitchValue, YawValue, RollValue);
	FQuat quaternion = FQuat(rotation);
	AddActorLocalRotation(quaternion, false, nullptr, ETeleportType::None);
}

