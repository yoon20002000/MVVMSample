// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVMSampleGameMode.h"
#include "MVVMSampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMVVMSampleGameMode::AMVVMSampleGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
