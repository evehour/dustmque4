// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CHitComponent.generated.h"

UCLASS()
class U04_FPSCPP_API ACHitComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACHitComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
public:
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UFUNCTION(BlueprintNativeEvent)
		void OnBeginOverlap
		(
			UPrimitiveComponent* OverComp
			, AActor* OtherActor
			, UPrimitiveComponent* OtherComp
			, FVector NormalImpulse//, int32 OtherBodyIndex 오버랩은 이게 아님.
			//, bool bFromSweep // 오버랩일 때만 있는거라 뺌.
			, const FHitResult& Result
		);

	void OnBeginOverlap_Implementation
	(
		UPrimitiveComponent* OverComp
		, AActor* OtherActor
		, UPrimitiveComponent* OtherComp
		, FVector NormalImpulse//, int32 OtherBodyIndex 오버랩은 이게 아님.
		//, bool bFromSweep // 오버랩일 때만 나타남
		, const FHitResult& Result
	);
};
