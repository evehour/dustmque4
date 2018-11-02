// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameMode.h"
#include "EngineUtils.h"

#include "CPlayer.h"
#include "Blueprint/UserWidget.h"

ACGameMode::ACGameMode()
{
	PrimaryActorTick.bCanEverTick = true; // �̰� ����� ƽ�� ȣ���.
}

void ACGameMode::BeginPlay()
{
	Super::BeginPlay();

	//���� ã��
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


