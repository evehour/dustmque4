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

	// 이게 뭐냐면 메테리얼 원보 자체로는 값을 수정할 수 없기 때문에 복사해서 값을 넣으려고
	// 만드는 것임.
	// 값을 임의로 동적으로 넣기 위해 뒤에 다이나믹이 붙은거임.
	UMaterialInstanceDynamic* RedBodyMaterial;

	UCapsuleComponent* MainCapsule;

	class UAnimMontage* DeathMontage;
};
