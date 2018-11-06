// Fill out your copyright notice in the Description page of Project Settings.

#include "CSweepActor.h"
#include "DrawDebugHelpers.h"

#include "EngineUtils.h"
#include "Engine/Public/WorldCollision.h"

#include "CConsoleLog.h"


// Sets default values
ACSweepActor::ACSweepActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACSweepActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACSweepActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector SweepStart = GetActorLocation();
	FVector SweepEnd = GetActorLocation();

	FCollisionShape collisionShape = FCollisionShape::MakeSphere(500); // 충돌 반경

	DrawDebugSphere(GetWorld(), SweepStart, collisionShape.GetSphereRadius(), 50, FColor::Blue, true, FLT_MAX);

	TArray<FHitResult> outHits;
	//
	bool bHit = GetWorld()->SweepMultiByChannel
	(
		outHits,
		SweepStart,
		SweepEnd,
		FQuat::Identity,
		ECC_WorldStatic, // WorldDynamic은 폰이고 뭐고 다 포함
		collisionShape
	);
	//GetWorld()->SweepMultiByObjectType()
	if (bHit == true)
	{
		for (FHitResult& result : outHits)
		{
			Print(*result.Actor->GetName());
		}
	}

}

