// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CTrigger.generated.h"

UCLASS()
class U04_FPSCPP_API ACTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(AActor* actor, AActor* other);

	UFUNCTION(BlueprintCallable)
		void OnOverlapEnd(AActor* actor, AActor* other);

private:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	
};
