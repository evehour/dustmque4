// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimPlayer.generated.h"

/**
 * 
 */
UCLASS()
class SGAUNREAL_API UCAnimPlayer : public UAnimInstance
{
	GENERATED_BODY()

public:
	UCAnimPlayer();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
		bool bWalking;

	UFUNCTION(BlueprintCallable)
		void UpdateSpeed();

public:
	// Called every frame
	virtual void NativeUpdateAnimation(float delta) override;
	
	
};
