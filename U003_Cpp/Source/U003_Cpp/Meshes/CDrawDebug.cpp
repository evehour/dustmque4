// Fill out your copyright notice in the Description page of Project Settings.

#include "CDrawDebug.h"
#include "DrawDebugHelpers.h"


// Sets default values
ACDrawDebug::ACDrawDebug()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CircleMatrix = FMatrix::Identity;

	Location = FVector(0, 0, 500);
	Location2 = FVector(0, -500, 500);
	Location3 = FVector(0, 500, 500);
	Location4 = FVector(-250, 0, 500);
	Location5 = FVector(-200, -500, 500);

	TestBox = FBox(FVector(0, 0, 0), FVector(200, 200, 200));
}

// Called when the game starts or when spawned
void ACDrawDebug::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugPoint(GetWorld(), Location, 100, FColor(0, 255, 0), true, MAX_FLT);
	DrawDebugSphere(GetWorld(), Location2, 100, 100, FColor(255, 0, 0), true, MAX_FLT, 0, 2);
	DrawDebugCircle(GetWorld(), CircleMatrix, 200, 50, FColor(200, 200, 100), true, MAX_FLT);
	DrawDebugCircle(GetWorld(), Location4, 200, 50, FColor(0, 0, 0), true, MAX_FLT);
	DrawDebugSolidBox(GetWorld(), TestBox, FColor(0, 0, 255), TestTransform, true, MAX_FLT);
	DrawDebugBox(GetWorld(), Location5, FVector(100, 100, 100), FColor::Yellow, true, MAX_FLT);
	DrawDebugLine(GetWorld(), Location2, Location3, FColor::Emerald, true, MAX_FLT, 0, 2);
	DrawDebugDirectionalArrow(GetWorld(), FVector(-300, 600, 600), FVector(-300, -600, 600), 120, FColor::Magenta, true, MAX_FLT);
	DrawDebugCrosshairs(GetWorld(), FVector(0, 0, 1000), FRotator(0, 0, 0), 500, FColor::White, true, MAX_FLT);
}

// Called every frame
void ACDrawDebug::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

