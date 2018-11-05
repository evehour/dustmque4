// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "U04_FpsCppGameMode.h"
#include "U04_FpsCppHUD.h"
#include "U04_FpsCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AU04_FpsCppGameMode::AU04_FpsCppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AU04_FpsCppHUD::StaticClass();
}
