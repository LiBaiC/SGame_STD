// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "SGame.h"
#include "SGameGameMode.h"
#include "SGamePlayerController.h"

ASGameGameMode::ASGameGameMode()
{
	// no pawn by default
	DefaultPawnClass = NULL;
	// use our own player controller class
	PlayerControllerClass = ASGamePlayerController::StaticClass();

	UE_LOG(LogSGameProcedure, Log, TEXT("Constrctor Start!"));
}

void ASGameGameMode::BeginPlay()
{
	Super::BeginPlay();

	//��ʼ����������Ϣ 
	MessageEndpoint = FMessageEndpoint::Builder("Gameplay_GameMode") //()Ϊ��ַ����
		.Handling<FMessage_Gameplay_GameStatusUpdate>(this, &ASGameGameMode::HandleGameStatusUpdate);  //ģ�庯��
	check(MessageEndpoint.IsValid());
	MessageEndpoint->Subscribe<FMessage_Gameplay_GameStatusUpdate>();
}


void ASGameGameMode::HandleGameStatusUpdate(const FMessage_Gameplay_GameStatusUpdate& Message, const IMessageContextRef& Context)
{
	CurrentGameGameStatus = Message.NewGameStatus;
	switch (CurrentGameGameStatus)
	{
	case ESGGameStatus::EGS_RondBegin:
		OnBeginRound();
		break;
	case ESGGameStatus::EGS_PlayerTurnBegin:
		OnPlayerTurnBegin();
		break;
	case ESGGameStatus::EGS_PlayerRegengerate:
		OnPlayerRegenerate();
		break;
	case ESGGameStatus::EGS_PlayerSkillCD:
		OnPlayerSkillCD();
		break;
	case ESGGameStatus::EGS_PlayerBeginInput:
		OnPlayerBeginInputStage();
		break;
	case ESGGameStatus::EGS_PlayerEndBuildPath:
		OnPlayerEndBuildPathStage();
		break;
	case ESGGameStatus::EGS_PlayerEndInput:
		OnPlayerEndInputStage();
		break;
	case ESGGameStatus::EGS_EnemyAttack:
		OnEnemyAttackStage();
		break;
	case ESGGameStatus::EGS_RoundEnd:
		OnRoundEndStage();
		break;
	case ESGGameStatus::EGS_GameOver:
		OnGameOver();
		break;
	default:
		UE_LOG(LogSGameProcedure, Error, TEXT("Unhandled game status!"));
		break;
	}
}

void ASGameGameMode::OnBeginRound()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Round Begin!"));
	
	//ʹ�ö���֮ǰȷ�ϺϷ���
	check(MessageEndpoint.IsValid());

	//newһ�������ڶ��У�����ջ�ϣ����뿪����֮���������ڲ�����ʧ�� �㸺�𴴽���Unreal Message Bus ��������ڴ�
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();

	//������״̬���ͳ�ȥ
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerTurnBegin;
	MessageEndpoint->Publish(Message,EMessageScope::Process);
}

void ASGameGameMode::OnPlayerTurnBegin()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player Turn Begin"));

	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerRegengerate;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerRegenerate()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player Regenerate"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerSkillCD;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerSkillCD()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player SkillCD"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerBeginInput;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerBeginInputStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player BeginInput"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerEndBuildPath;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerEndBuildPathStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player EndBuildPath"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_PlayerEndInput;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnPlayerEndInputStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Player EndInput"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_EnemyAttack;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnEnemyAttackStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Enemy Attack"));
	check(MessageEndpoint.IsValid());
	FMessage_Gameplay_GameStatusUpdate* Message = new FMessage_Gameplay_GameStatusUpdate();
	Message->NewGameStatus = ESGGameStatus::EGS_RoundEnd;
	MessageEndpoint->Publish(Message, EMessageScope::Process);
}

void ASGameGameMode::OnRoundEndStage()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Round End"));

}

void ASGameGameMode::OnGameOver()
{
	UE_LOG(LogSGameProcedure, Log, TEXT("Goto Stage: Game Over"));

}

