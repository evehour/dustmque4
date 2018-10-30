// Fill out your copyright notice in the Description page of Project Settings.

#include "CPlayer.h"
#include "CConsoleLog.h"

#include "Animation/AnimMontage.h"


// Sets default values
ACPlayer::ACPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> attack
	{
		TEXT("/Game/Blueprints/BpAnimMonSwordAttack")
	};
	AttackMontage = attack.Object;


	static ConstructorHelpers::FObjectFinder<UAnimMontage> jump
	{
		TEXT("/Game/Blueprints/BpAnimMonSwordJump")
	};
	JumpMontage = jump.Object;

	//AIControllerClass = StaticClass();
	AutoPossessAI = EAutoPossessAI::Spawned;
}

// Called when the game starts or when spawned
void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void ACPlayer::MoveForward(float axisValue)
{
	if (bAttack) return;

	FVector vec = FVector(1, 0, 0);
	AddMovementInput(vec, axisValue);
}


void ACPlayer::MoveRight(float axisValue)
{
	if (bAttack) return;

	FVector vec = FVector(0, 1, 0);
	AddMovementInput(vec, axisValue);
}

void ACPlayer::Attacking()
{
	if (bAttack) return;

	bAttack = true;
	PlayAnimMontage(AttackMontage);
}

void ACPlayer::OnEndAttack()
{
	bAttack = false;
}

void ACPlayer::Jumping()
{
	bool bFalling = GetCharacterMovement()->IsFalling();

	if (!bFalling && !bAttack)
	{
		PlayAnimMontage(JumpMontage);
		Jump();
	}
}
