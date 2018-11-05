// Fill out your copyright notice in the Description page of Project Settings.

#include "CHideActor.h"
#include "Engine/World.h"


// Sets default values
ACHideActor::ACHideActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACHideActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (HideInGame == true)
		DisableActor(HideInGame);
}

// Called every frame
void ACHideActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetWorld()->GetNumPawns(); // 배치되어진 폰들이 넘어옴.
	GetWorld()->GetPawnIterator(); // 배치되어진 폰들의 이터레이터가 넘어옴. 액터가 아님!
}

void ACHideActor::DisableActor(bool bHide)
{
	SetActorHiddenInGame(bHide);
	SetActorEnableCollision(!bHide);
	SetActorTickEnabled(!bHide); // 생성자의 PrimaryActorTick.bCanEverTick 옵션과 동일
}

