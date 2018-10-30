// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CGoblin.generated.h"

UENUM(BlueprintType)
enum class GoblinState : uint8
{
	Idle = 0, Follow, Attack, Death,
};

UCLASS()
class U02_CHARACTER_API ACGoblin : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACGoblin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void GetPlayerDistanceAndDirection();

public:
	UPROPERTY(EditAnywhere)
		float Hp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Distance;

	UPROPERTY(EditAnywhere)
		float AttackDistance;

	UFUNCTION(BlueprintCallable)
		void OnEndAttack();

	void Damaged(float damage);
	void DamagedComplete();

private:
	void Idling();
	void Following();
	//void Attacking();
	void Dying();
	void DyingComplete();

private:
	bool bDeath;

	float DistanceToPlayer;
	FVector DirectionToPlayer;

	GoblinState State;
	
	UMaterial* BodyMaterial;

	// �̰� ���ĸ� ���׸��� ���� ��ü�δ� ���� ������ �� ���� ������ �����ؼ� ���� ��������
	// ����� ����.
	// ���� ���Ƿ� �������� �ֱ� ���� �ڿ� ���̳����� ��������.
	UMaterialInstanceDynamic* RedBodyMaterial;

	UCapsuleComponent* MainCapsule;

	class UAnimMontage* DeathMontage;
};