// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class SGAUNREAL_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
		AActor* CameraObject;

	UFUNCTION(BlueprintCallable)
		void OnEndAttack();

private:
	UPROPERTY(VisibleAnywhere)
		class UAnimMontage* AttackMontage;

	UPROPERTY(VisibleAnywhere)
		class UAnimMontage* JumpMontage;

	bool bAttack;
	
public:
	void MoveForward(float axisValue);
	void MoveRight(float axisValue);

	void Attacking();
	void Jumping();
};
