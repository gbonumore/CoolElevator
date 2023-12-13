// Copyright Epic Games, Inc. All Rights Reserved.

#include "ElevatorGameMode.h"
#include "ElevatorCharacter.h"
#include "UObject/ConstructorHelpers.h"

AElevatorGameMode::AElevatorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
