// Fill out your copyright notice in the Description page of Project Settings.

#include "CHitComponent.h"

#include "Components/BoxComponent.h"

#include "../CConsoleLog.h"
#include "DrawDebugHelpers.h"


// Sets default values
ACHitComponent::ACHitComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	Box->SetSimulatePhysics(true);
	Box->SetNotifyRigidBodyCollision(true); // 이게 안켜면 충돌을 안받음. 캐릭터는 오토지만 액터라 기본으로 꺼져있을꺼임.

	// BodyInstance: 블루프린트에 컴포넌트쪽 액터 밑에있는 가장 최상위에있는 '디폴트씬루트'를 의미
	// 컬리젼 쪽에있는 컬리전 프리셋을 지정하는 것임.
	// Block은 통과가 아니라 튕겨져 나가게금 하는 것.
	Box->BodyInstance.SetCollisionProfileName("BlockAllDynamic");

	
	// 블록이라서 오버랩이 아니라 힛으로 해야 함.
	Box->OnComponentHit.AddDynamic(this, &ACHitComponent::OnBeginOverlap);

	RootComponent = Box;
}

// Called when the game starts or when spawned
void ACHitComponent::BeginPlay()
{
	Super::BeginPlay();
	
	FVector location = GetActorLocation();
	DrawDebugBox(GetWorld(), location, FVector(1, 1, 1), FColor::Yellow, true, MAX_FLT);
}

// Called every frame
void ACHitComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACHitComponent::OnBeginOverlap_Implementation(UPrimitiveComponent * OverComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Result)
{
	if (OtherActor != NULL && OtherActor != this && OtherComp != NULL)
	{
		PrintFormat("%s", *OtherActor->GetFName().ToString());
	}
}

