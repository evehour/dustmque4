// Fill out your copyright notice in the Description page of Project Settings.

#include "CAnimPlayer.h"
#include "CConsoleLog.h"

UCAnimPlayer::UCAnimPlayer()
{
	bWalking = false;
}

// Called every frame
void UCAnimPlayer::NativeUpdateAnimation(float delta)
{
	APawn* pawn = TryGetPawnOwner();
	if (pawn == NULL)
		return;

	FVector vec = pawn->GetVelocity();
	float speed = vec.Size();

	bWalking = speed >= 0.1f;
}