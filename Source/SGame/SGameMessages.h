#pragma once

#include "SGameMessages.generated.h"

/** Defines the game state */
UENUM()
enum class ESGGameStatus : uint8
{
	EGS_Init,					// Initial value
	EGS_GameStart,				// Game start
	EGS_RondBegin,				// New round begin
	EGS_PlayerTurnBegin,		// Player turn begin
	EGS_PlayerRegengerate,		// Player regenerate
	EGS_PlayerSkillCD,			// Player skill CD
	EGS_PlayerBeginInput,		// Player begin input, can link line or use the skill
	EGS_PlayerEndBuildPath,		// Player end build the path, but he can still use skill or buy some thing
	EGS_PlayerEndInput,			// Player end input, his turn end
	EGS_EnemyAttack,			// Enemy attack player
	EGS_RoundEnd,				// End of the round
	EGS_GameOver,				// Game over
};


/**
* Game status update messages
*/
USTRUCT()
struct FMessage_Gameplay_GameStatusUpdate
{
	GENERATED_USTRUCT_BODY()

	/** The new game status */
	UPROPERTY()
	ESGGameStatus NewGameStatus;
};
