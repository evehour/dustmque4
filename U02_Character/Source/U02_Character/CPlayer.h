// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class U02_CHARACTER_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACPlayer();

	UPROPERTY(EditAnywhere)
		AActor* CameraObject;

	UPROPERTY(EditAnywhere)
		TSubclassOf<class UCameraShake> CameraShake;

	UPROPERTY(EditAnywhere)
		float Attack;

	UFUNCTION(BlueprintCallable)
		void OnEndAttack();

	UFUNCTION(BlueprintCallable)
		void OnCheckCombo();

	UFUNCTION(BlueprintCallable)
		void OnFinishCombo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//
	//UPROPERTY(EditAnywhere)
	//	int Test;

	//UFUNCTION(BlueprintCallable)
	//	int PrintTest(int val);

public:
	// bluePrint랑 똑같이 인자받아야함
	void MoveForward(float axisValue);
	void MoveRight(float axisValue);

	void Attacking();
	void Jumping();

	void Damaged(float damage);
	void DamagedComplete();

	UFUNCTION(BlueprintNativeEvent)
		void OnBeginOverlap
		(
			UPrimitiveComponent* OverComp
			, AActor* OtherActor
			, UPrimitiveComponent* OtherComp
			, int32 OtherBodyIndex
			, bool bFromSweep
			, const FHitResult& SweepResult
		);

	void OnBeginOverlap_Implementation
	(
		UPrimitiveComponent* OverComp
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, int32 OtherBodyIndex
		, bool bFromSweep
		, const FHitResult& SweepResult
	);

private:
	void FinishComboComplete();

private:
	//class UCameraShake* CameraShake;
	//TSubclassOf<class UCameraShake> CameraShake;

	UPROPERTY(VisibleAnywhere)
	class UAnimMontage* AttackMontage[3];
	class UAnimMontage* JumpMontage;

	class UCapsuleComponent* WeaponCapsule;

	class UParticleSystemComponent* FinishComboParticle;

	UMaterial* BodyMaterial;
	UMaterial* RedMaterial;

	bool bAttack;
	bool bNextCombo;
	int ComboCount;
};
