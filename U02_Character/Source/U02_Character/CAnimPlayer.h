// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimPlayer.generated.h"

/**
 * 
 */
UCLASS()
class U02_CHARACTER_API UCAnimPlayer : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UCAnimPlayer();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
		bool bWalking;

public:
	// Called every frame
	virtual void NativeUpdateAnimation(float delta) override;

};
