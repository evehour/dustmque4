// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CGameManager.generated.h"

UCLASS()
class SGAUNREAL_API ACGameManager : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	//class ACCamera* Camera;
	TSubclassOf<class ACPlayer> playerBlueprint;
	class ACPlayer* player;

	void MoveForward(float axisValue);
	void MoveRight(float axisValue);
	void Attacking();
	void Jumping();
	
};
