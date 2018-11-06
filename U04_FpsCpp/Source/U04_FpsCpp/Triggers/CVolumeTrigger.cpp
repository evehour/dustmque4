// Fill out your copyright notice in the Description page of Project Settings.

#include "CVolumeTrigger.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"


// Sets default values
ACVolumeTrigger::ACVolumeTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	LightIntensity = 3000.0f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(FName("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = true;
	RootComponent = PointLight;

	Sphere = CreateDefaultSubobject<USphereComponent>(FName("Sphere"));
	Sphere->InitSphereRadius(300.0f);
	Sphere->SetCollisionProfileName(FName("Trigger"));
	Sphere->SetupAttachment(RootComponent);

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ACVolumeTrigger::OnOverlapBegin);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ACVolumeTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ACVolumeTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACVolumeTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACVolumeTrigger::OnOverlapBegin_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
}

void ACVolumeTrigger::OnOverlapEnd_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}

void ACVolumeTrigger::Toggle()
{
}

