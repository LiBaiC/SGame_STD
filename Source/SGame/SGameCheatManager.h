// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CheatManager.h"
#include "SGameCheatManager.generated.h"

/**
 * 
 */
UCLASS(Within = SGamePlayerController)
class SGAME_API USGameCheatManager : public UCheatManager
{
	GENERATED_BODY()
	
public :
	USGameCheatManager();

	UFUNCTION(exec)    //exec的作用是在命令行的参数需要被捕捉并解析执行下面的定义的方法
	void StartGame();
private:
	FMessageEndpointPtr MessageEndpoint;
	
};
