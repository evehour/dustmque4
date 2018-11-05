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
	Box->SetNotifyRigidBodyCollision(true); // �̰� ���Ѹ� �浹�� �ȹ���. ĳ���ʹ� �������� ���Ͷ� �⺻���� ������������.

	// BodyInstance: �������Ʈ�� ������Ʈ�� ���� �ؿ��ִ� ���� �ֻ������ִ� '����Ʈ����Ʈ'�� �ǹ�
	// �ø��� �ʿ��ִ� �ø��� �������� �����ϴ� ����.
	// Block�� ����� �ƴ϶� ƨ���� �����Ա� �ϴ� ��.
	Box->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	
	// ����̶� �������� �ƴ϶� ������ �ؾ� ��.
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

