// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "U003_CppGameMode.h"
#include "U003_CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AU003_CppGameMode::AU003_CppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
