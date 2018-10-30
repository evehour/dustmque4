// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimGoblin.generated.h"

/**
 * 
 */
UCLASS()
class U02_CHARACTER_API UCAnimGoblin : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UCAnimGoblin();

	UPROPERTY(EditAnyWhere, BlueprintReadOnly)
		bool bWalking;

	virtual void NativeUpdateAnimation(float delta) override;
		
};
