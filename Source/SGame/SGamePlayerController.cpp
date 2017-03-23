// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SGame.h"
#include "SGamePlayerController.h"
#include "SGameCheatManager.h"

ASGamePlayerController::ASGamePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	CheatClass = USGameCheatManager::StaticClass();
}
