// Fill out your copyright notice in the Description page of Project Settings.

#include "CStaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"


// Sets default values
ACStaticMesh::ACStaticMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���� �����ϱ�
	//Actor�� ��ӹ޴� �ִ� CreateDefaultSubobject �� ����ؾ���.
	UStaticMeshComponent* cylinder = CreateDefaultSubobject<UStaticMeshComponent>(FName("MyCylinder"));
	//���ʹ� �ݵ�� ������ �־���ϴ� ���� RootComponent�̴�.
	cylinder->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> meshCylinder
	(
		TEXT("/Game/StarterContent/Shapes/Shape_Cylinder")
	);
	if (meshCylinder.Succeeded())
	{
		cylinder->SetStaticMesh(meshCylinder.Object);
		cylinder->SetRelativeLocation(FVector(0, 0, 0));//Local�ν� �����Ų ��ġ��� ������~��
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

