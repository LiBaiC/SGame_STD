// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "SGamePlayerController.generated.h"

/** PlayerController class used to enable cursor */
UCLASS()
class ASGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASGamePlayerController();
private:
	FMessageEndpointPtr MessageEndpoint;
};


