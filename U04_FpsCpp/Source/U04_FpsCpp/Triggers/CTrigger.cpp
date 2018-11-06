// Fill out your copyright notice in the Description page of Project Settings.

#include "CTrigger.h"
#include "DrawDebugHelpers.h"

#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"

#include "Components/BoxComponent.h"

#include "CConsoleLog.h"

// Sets default values
ACTrigger::ACTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Box->BodyInstance.SetCollisionProfileName("OverlapAll");
	Box->SetSimulatePhysics(false);
	Box->SetNotifyRigidBodyCollision(true); // 이게 안켜면 충돌을 안받음. 캐릭터는 오토지만 액터라 기본으로 꺼져있을꺼임.
	RootComponent = Box;

	OnActorBeginOverlap.AddDynamic(this, &ACTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ACTrigger::BeginPlay()
{
	Super::BeginPlay();

	FBox collisionArea = FBox::BuildAABB(FVector(0, 0, 0), FVector(64, 64, 64));

	DrawDebugBox
	(
		GetWorld(),
		GetActorLocation(),
		collisionArea.GetExtent(), // 넓이
		FColor::Purple,
		true,
		FLT_MAX,
		0,
		3.0f
	);
}

// Called every frame
void ACTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ACTrigger::OnOverlapBegin(AActor* actor, AActor* other)
{
	AActor* player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (other != NULL && other != this && player == other)
	{
		Print("OverlapBegin");
		Print(*other->GetName());
	}
}

void ACTrigger::OnOverlapEnd(AActor* actor, AActor* other)
{
	AActor* player = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (other != NULL && other != this && player == other)
	{
		Print("OverlapEnd");
		Print(*other->GetName());
	}
}