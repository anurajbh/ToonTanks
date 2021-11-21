// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerTank.h"
#include "EnemyTurret.h"
#include "ToonTanksPlayerController.h"
#define OUT
void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == PlayerCharacter)
	{
		PlayerCharacter->HandleDestruction();
		if (PlayerController)
		{
			PlayerController->SetPlayerEnabledState(false);
		}
		GameOver(false);
	}
	else if (AEnemyTurret* DestroyedTurret = Cast<AEnemyTurret>(DeadActor))
	{
		DestroyedTurret->HandleDestruction();
		NumberOfTowers--;
		if (NumberOfTowers <= 0)
		{
			GameOver(true);
		}
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
	StartGame();
	if (PlayerController)
	{
		PlayerController->SetPlayerEnabledState(false);
		FTimerHandle PlayerEnableTimerHandle;
		FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(PlayerController, &AToonTanksPlayerController::SetPlayerEnabledState, true);
		GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
		NumberOfTowers = GetNumberOfTowers();
	}
}
int32 AToonTanksGameMode::GetNumberOfTowers()
{
	TArray<AActor*> ArrayOfTowers;
	UGameplayStatics::GetAllActorsOfClass(this, AEnemyTurret::StaticClass(), OUT ArrayOfTowers);
	return ArrayOfTowers.Num();
}