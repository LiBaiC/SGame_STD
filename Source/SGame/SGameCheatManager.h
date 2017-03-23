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

	UFUNCTION(exec)    //exec���������������еĲ�����Ҫ����׽������ִ������Ķ���ķ���
	void StartGame();
private:
	FMessageEndpointPtr MessageEndpoint;
	
};
