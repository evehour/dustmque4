// Fill out your copyright notice in the Description page of Project Settings.

#include "CCamera.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "CConsoleLog.h"


// Sets default values
ACCamera::ACCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->AutoPossessAI = EAutoPossessAI::Spawned;
}

// Called when the game starts or when spawned
void ACCamera::BeginPlay()
{
	Super::BeginPlay();

	Print("Open");

	if (Camera == NULL)
	{
		return;
	}

	//�÷��̾� ��Ʈ�ѷ� ������Ʈ�� �޾ƿ;���.
	APlayerController* controller = GetWorld()->GetFirstPlayerController();

	if (controller == NULL) return;

	controller->SetViewTargetWithBlend(Camera, 0);

	// InputComponent �����ڴ� ����÷��� �������� ����Ǳ� ������ ���� �����ڿ����� �ϸ� �ȵȴ�.
	//InputComponent = 
	
}

// Called every frame
void ACCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//InputComponent->BindAction("Camera", IE_Pressed, this, &ACCamera::ChangeView);
	//InputComponent->BindAction("Camera2", IE_Pressed, this, &ACCamera::ChangeView2);
}

void ACCamera::ChangeView()
{
	if (Camera == NULL) return;

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (controller == NULL) return;

	controller->SetViewTargetWithBlend(Camera, 1.0f);
}

void ACCamera::ChangeView2()
{
	if (Camera2 == NULL) return;

	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	if (controller == NULL) return;

	controller->SetViewTargetWithBlend(Camera2, 1.0f);
}
