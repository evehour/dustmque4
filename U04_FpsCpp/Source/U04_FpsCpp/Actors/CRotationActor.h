// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRotationActor.generated.h"

UCLASS()
class U04_FPSCPP_API ACRotationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACRotationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (DisplayName = "Pitch"))
		float PitchValue;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (DisplayName = "Yaw"))
		float YawValue;

	UPROPERTY(EditAnywhere, Category = "Movement", meta = (DisplayName = "Roll"))
		float RollValue;
	
};
