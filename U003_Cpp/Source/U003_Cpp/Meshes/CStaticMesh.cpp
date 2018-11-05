// Fill out your copyright notice in the Description page of Project Settings.

#include "CStaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"


// Sets default values
ACStaticMesh::ACStaticMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 액터 생성하기
	//Actor를 상속받는 애는 CreateDefaultSubobject 를 사용해야함.
	UStaticMeshComponent* cylinder = CreateDefaultSubobject<UStaticMeshComponent>(FName("MyCylinder"));
	//액터는 반드시 가지고 있어야하는 것이 RootComponent이다.
	cylinder->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshCylinder
	(
		TEXT("/Game/StarterContent/Shapes/Shape_Cylinder")
	);
	if (meshCylinder.Succeeded())
	{
		cylinder->SetStaticMesh(meshCylinder.Object);
		cylinder->SetRelativeLocation(FVector(0, 0, 0));//Local로써 적용시킨 위치라고 생각해~ㅎ
		cylinder->SetWorldScale3D(FVector(2));
	}
}

// Called when the game starts or when spawned
void ACStaticMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACStaticMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

