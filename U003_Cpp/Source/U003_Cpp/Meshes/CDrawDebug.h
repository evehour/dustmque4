// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CDrawDebug.generated.h"

UCLASS()
class U003_CPP_API ACDrawDebug : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACDrawDebug();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere)
		FVector Location;

	UPROPERTY(EditAnywhere)
		FVector Location2;

	UPROPERTY(EditAnywhere)
		FVector Location3;

	UPROPERTY(EditAnywhere)
		FVector Location4;

	UPROPERTY(EditAnywhere)
		FVector Location5;

	UPROPERTY(EditAnywhere)
		FMatrix CircleMatrix;

	UPROPERTY(EditAnywhere)
		FBox TestBox;

	UPROPERTY(EditAnywhere)
		FTransform TestTransform;
};
