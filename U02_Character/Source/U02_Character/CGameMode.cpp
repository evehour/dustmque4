// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameMode.h"
#include "EngineUtils.h"

#include "CPlayer.h"
#include "Blueprint/UserWidget.h"

#include "CConsoleLog.h"

ACGameMode::ACGameMode()
{
	PrimaryActorTick.bCanEverTick = true; // 이걸 해줘야 틱이 호출됨.

	GoblinCount;
}

void ACGameMode::BeginPlay()
{
	Super::BeginPlay();

	//액터 찾기
	for (TActorIterator<ACPlayer> iter(GetWorld()); iter; ++iter)
	{
		player = *iter;
	}
}

void ACGameMode::Tick(float delta)
{
	Super::Tick(delta);

	float hp = player->Hp;
	PlayerHpRatio = hp / 100.0f;

}

void ACGameMode::AddGoblinCount()
{
	GoblinCount++;
}

void ACGameMode::SubGoblinCount()
{
	GoblinCount--;

	if (GoblinCount <= 0)
	{
		//TODO: 보스 출현
		Print("Spawn Boss!!");
	}
}

