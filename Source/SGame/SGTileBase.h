// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PaperSprite.h" 
#include "PaperSpriteActor.h"
#include "SGTileBase.generated.h"

/** Types of tile base type. */
UENUM()
enum class ESGTileType : uint8
{
	ETT_Sword = 0,					// Sword
	ETT_Shield = 1,					// Shield
	ETT_Potion = 2,					// Potion
	ETT_Coin = 3,					// Coin
	ETT_Mana = 4,					// Mana
	ETT_Arrow = 5,					// Arrow
	ETT_Soldier = 6					// Soldier
};



/** Types of every possible tile state flag that the tile will be in, note it can be in multiple state */
UENUM()
enum class ESGTileStatusFlag : uint8
{
	ESF_STATUS_CHANGED,		// Tile status has changed
	ESF_POISONED,			// Tile is posioned
	ESF_BURNING,			// Tile is burning
	ESF_PATH_TYPE,			// Tile is the same type as path
	ESF_DEAD,				// Tile is dead
	ESF_SELECTABLE,			// Tile is linkable
	ESF_MATCHABLE,			// Tile is matchable to the current path
	ESF_BROKEN,				// Tile is broken
	ESF_FROZEN,				// Tile is frozen
	ESF_LINKED,				// Tile is linked
};



/** Types of resource type. */
UENUM()
enum class ESGResourceType : uint8
{
	ETR_HP = 0,						// HP of the player
	ETT_Armor = 1,					// Armor of the player
	ETT_Money = 2,					// Money
	ETT_XP = 3,						// In game player xp
	ETT_MAX = 4,					// Max resource type
};

/** The tile resource unit, which can be collected */
USTRUCT()
struct FTileResourceUnit
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESGResourceType			ResourceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					ResourceAmount;
};


/** The damage info this tile can cause */
USTRUCT()
struct FTileDamageInfo
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					InitialDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					PiercingArmorRatio;
};

/** The life info for this tile, when the life reduce to 0, it will be collected*/
USTRUCT()
struct FTileLifeArmorInfo
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					LifeMax;			// The tile's life may regenerate too
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					CurrentLife;		// Current life of this tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					ArmorMax;			// The tile's armor may regenerate too
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float					CurrentArmor;		// Current armor of this tile
};


USTRUCT()
struct FSGTileAbilities
{
	GENERATED_USTRUCT_BODY();

	/** Whether can link enemy - (e.g sword or arrow)*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanLinkEnemy;

	/** Enemy tile which can cause damage to the player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bEnemyTile;

	/** Whether the enemy can take damage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanTakeDamage;

	/** Whether the enemy can take damage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanCauseDamage;

	/** Whether the enemy can cause custom behavior */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanCauseCustomBehavior;
};


USTRUCT()
struct FSGTileData
{
	GENERATED_USTRUCT_BODY();

public :
	/** The base type of the current tile*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESGTileType TileType;

	/** The current tile status flag, should not be accessed anywhere, for test convenient now*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ESGTileStatusFlag> TileStatusArray;

	/** The current tile resource info*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FTileResourceUnit> TileResourceArray;

	/** The current tile damage info, only valid if the tile can cause damage*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTileDamageInfo CauseDamageInfo;

	/** The current tile damage info, only valid if the tile can take damage*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTileLifeArmorInfo LifeArmorInfo;
};

/**
 * 
 */
UCLASS()
class SGAME_API ASGTileBase : public APaperSpriteActor
{
	GENERATED_BODY()
	
public :
	//Sets default values for this actor's properties
	ASGTileBase();

	UPROPERTY(BlueprintReadOnly)
		int32 TileTypeID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSGTileAbilities Abilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FSGTileData Data;



protected:
	/** Location on the grid as a 1D key/value. To find neighbors, ask the grid. */
	UPROPERTY(BlueprintReadOnly, Category = Tile)
		int32 GridAddress;

	// The sprite asset for link corners 45 degree
	UPROPERTY(Category = Sprite, EditAnywhere, BlueprintReadOnly, meta = (DisplayThumbnail = "true"))
		UPaperSprite* Sprite_Selected;

	// The sprite asset for link corners 45 degree
	UPROPERTY(Category = Sprite, EditAnywhere, BlueprintReadOnly, meta = (DisplayThumbnail = "true"))
		UPaperSprite* Sprite_Normal;

	int32 TileID;

private:
	// Holds the messaging endpoint.
	// Note that we don't want the sub class inherited this member,
	// because every message handler should explicitly handled by itself class
	FMessageEndpoint MessageEndpoint;


};
