// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CGameMode.generated.h"

/**
 * 
 */
UCLASS()
class U02_CHARACTER_API ACGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACGameMode();

	UPROPERTY(BlueprintReadOnly)
		float PlayerHpRatio;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float delta) override;
	
private:
	class ACPlayer* player;
};
