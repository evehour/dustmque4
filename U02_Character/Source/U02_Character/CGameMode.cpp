// Fill out your copyright notice in the Description page of Project Settings.

#include "CGameMode.h"
#include "EngineUtils.h"

#include "CPlayer.h"
#include "Blueprint/UserWidget.h"

ACGameMode::ACGameMode()
{
	PrimaryActorTick.bCanEverTick = true; // ¿Ã∞… «ÿ¡‡æﬂ ∆Ω¿Ã »£√‚µ .

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

	//æ◊≈Õ √£±‚
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


