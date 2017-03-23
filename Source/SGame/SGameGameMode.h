// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "SGameMessages.h"
#include "SGameGameMode.generated.h"

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi)
class ASGameGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ASGameGameMode();
	virtual void BeginPlay() override;

private:
	FMessageEndpointPtr MessageEndpoint;

	ESGGameStatus CurrentGameGameStatus;

	void HandleGameStatusUpdate(const FMessage_Gameplay_GameStatusUpdate& Message, const IMessageContextRef& Context);
	void OnBeginRound();
	void OnPlayerTurnBegin();
	void OnPlayerRegenerate();
	void OnPlayerSkillCD();
	void OnPlayerBeginInputStage();
	void OnPlayerEndBuildPathStage();
	void OnPlayerEndInputStage();
	void OnEnemyAttackStage();
	void OnRoundEndStage();
	void OnGameOver();
};



