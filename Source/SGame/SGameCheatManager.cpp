// Fill out your copyright notice in the Description page of Project Settings.

#include "SGame.h"
#include "SGameCheatManager.h"
#include "SGameMessages.h"

USGameCheatManager::USGameCheatManager()
{
	MessageEndpoint = FMessageEndpoint::Builder("CheatManagerMessageEP");
}



void USGameCheatManager::StartGame()
{
	UE_LOG(LogSGameProcedure,Log,TEXT("Force start Game"));

	//����һ����Ϣ����Ϣ������
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_RondBegin;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}
