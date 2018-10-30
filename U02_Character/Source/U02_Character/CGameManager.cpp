// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameManager.h"
#include "CCamera.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "CConsoleLog.h"
#include "CPlayer.h"

// Sets default values
ACGameManager::ACGameManager()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> playerBp
	(
		TEXT("/Game/BpC/BpCPlayer")
	);

	if (playerBp.Object != NULL)
		playerBlueprint = (UClass *)playerBp.Object->GeneratedClass;

}

// Called when the game starts or when spawned
void ACGameManager::BeginPlay()
{
	Super::BeginPlay();
	
	//���� Ŭ���� ��ü ����
	//FVector location(0, 0, 0);
	//FRotator rotation(0, 0, 0);
	//
	//cameraActor = GetWorld()->SpawnActor<ACCamera>(location, rotation);

	//�������Ʈ Ŭ���� ��ü ����
	//FActorSpawnParameters params;
	////Owns�� �����ϰ� this ���ָ� �ڽ����� ����
	////params.Instigator = this;
	//params.Owner = this;
	//player = GetWorld()->SpawnActor<ACPlayer>(playerBlueprint, GetActorLocation(), GetActorRotation(), params);
	//

	//���� ã��
	//int i = 0;
	//ACameraActor* actor[2];
	//
	//for (TActorIterator<ACameraActor> iter(GetWorld()); iter; ++iter)
	//{
	//	if (iter->GetFName() != "CameraActor_0")
	//	{
	//		if (iter->GetName() == "MainCamera")
	//			actor[0] = *iter;
	//		else
	//			actor[1] = *iter;
	//	}
	//}
	//
	//cameraActor->Camera = actor[0];
	//cameraActor->Camera = actor[1];
	
	ChangeCamera2();


	//PrintFormat("%d", actor[0] != NULL);
	//PrintFormat("%d", actor[1] != NULL);
	
	//�𸮾� � �߿� �ϳ�
	//check�� ������ ��� ���� ���� â�� �Բ� ������
	//check(actor[0] == NULL); //����
}

// Called every frame
void ACGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACGameManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAxis("MoveForward", this, &ACGameManager::MoveForward);
	//InputComponent->BindAxis("MoveRight", this, &ACGameManager::MoveRight);
	//
	//InputComponent->BindAction("Attack", IE_Pressed, this, &ACGameManager::Attacking);
	//InputComponent->BindAction("Jump", IE_Pressed, this, &ACGameManager::Jumping);
	//InputComponent->BindAction("Jump", IE_Released, this, &ACGameManager::StopJumping);
	//
	//InputComponent->BindAction("Camera", IE_Pressed, this, &ACGameManager::ChangeCamera);
	//InputComponent->BindAction("Camera2", IE_Pressed, this, &ACGameManager::ChangeCamera2);
}

void ACGameManager::ChangeCamera()
{
	cameraActor->ChangeView();
}

void ACGameManager::ChangeCamera2()
{
	cameraActor->ChangeView2();
}

void ACGameManager::MoveForward(float axisValue)
{
	player->MoveForward(axisValue);
}

void ACGameManager::MoveRight(float axisValue)
{
	player->MoveRight(axisValue);
}

void ACGameManager::Attacking()
{
	player->Attacking();
}

void ACGameManager::Jumping()
{
	player->Jumping();
}

