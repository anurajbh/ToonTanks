// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"
#include "EnemyTurret.h"
#include "ToonTanksPlayerController.h"
void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerCharacter)
	{
		PlayerCharacter->HandleDestruction();
		if (PlayerController)
		{
			PlayerController->SetPlayerEnabledState(false);
		}
	}
	else if (AEnemyTurret* DestroyedTurret = Cast<AEnemyTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
	}
}
void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();
	HandleGameStart();
}
void AToonTanksGameMode::HandleGameStart()
{
	PlayerCharacter = Cast<APlayerTank>(UGameplayStatics::GetPlayerPawn(this, 0));
	PlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerController)
	{
		PlayerController->SetPlayerEnabledState(false);
	}
}