// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameMode.h"
#include "EngineUtils.h"

#include "CPlayer.h"
#include "Blueprint/UserWidget.h"

ACGameMode::ACGameMode()
{
	PrimaryActorTick.bCanEverTick = true; // �̰� ����� ƽ�� ȣ���.

	static ConstructorHelpers::FClassFinder<UUserWidget> hpBar
	(
		TEXT("/Game/Widgets/PlayerHpBar")
	);
	HpBarWidget = hpBar.Class;
}

void ACGameMode::BeginPlay()
{
	if (HpBarWidget != NULL)
	{
		APlayerController* cont = GetWorld()->GetFirstPlayerController();
		HpBar = CreateWidget<UUserWidget>(cont, HpBarWidget);
	}

	//���� ã��
	for (TActorIterator<ACPlayer> iter(GetWorld()); iter; ++iter)
	{
		player = *iter;
	}
}

void ACGameMode::Tick(float delta)
{
	float hp = player->Hp;
	PlayerHpRatio = hp / 100.0f;

	
}


