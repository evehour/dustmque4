// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameManager.h"

#include "Engine/World.h"
#include "EngineUtils.h"
#include "CPlayer.h"

#include "CConsoleLog.h"


// Sets default values
ACGameManager::ACGameManager()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> playerBp
	(
		TEXT("/Game/Blueprints/BpCPlayer")
	);

	if (playerBp.Object != NULL)
	{
		playerBlueprint = playerBp.Object->GeneratedClass;
	}

}

// Called when the game starts or when spawned
void ACGameManager::BeginPlay()
{
	Super::BeginPlay();

	FActorSpawnParameters param;
	param.Owner = this;

	player = GetWorld()->SpawnActor<ACPlayer>(playerBlueprint, GetActorLocation(), GetActorRotation(), param);
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

	InputComponent->BindAxis("MoveForward", this, &ACGameManager::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACGameManager::MoveRight);

	InputComponent->BindAction("Attack", IE_Pressed, this, &ACGameManager::Attacking);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACGameManager::Jumping);
	InputComponent->BindAction("Jump", IE_Released, this, &ACGameManager::StopJumping);

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
