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

	GetWorld()->GetNumPawns(); // ��ġ�Ǿ��� ������ �Ѿ��.
	GetWorld()->GetPawnIterator(); // ��ġ�Ǿ��� ������ ���ͷ����Ͱ� �Ѿ��. ���Ͱ� �ƴ�!
}

void ACHideActor::DisableActor(bool bHide)
{
	SetActorHiddenInGame(bHide);
	SetActorEnableCollision(!bHide);
	SetActorTickEnabled(!bHide); // �������� PrimaryActorTick.bCanEverTick �ɼǰ� ����
}

