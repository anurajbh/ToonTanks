// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTurret.h"
#include "PlayerTank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
void AEnemyTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Find the distance to the tank
	//Check if within range
	//Rotate at tank
	if (CheckIfPlayerIsInRange())
	{
		RotateTurret(PlayerCharacter->GetActorLocation());
	}
	//Fire at tank if so
}
void AEnemyTurret::BeginPlay()
{
	Super::BeginPlay();
	PlayerCharacter = (APlayerTank*)UGameplayStatics::GetPlayerPawn(this, 0);
	GetWorldTimerManager().SetTimer(EnemyTimerHandle, this, &AEnemyTurret::CheckForFiring, FireRate, true);
}
void AEnemyTurret::CheckForFiring()
{
	if (CheckIfPlayerIsInRange())
	{
		Fire();
	}
}

bool AEnemyTurret::CheckIfPlayerIsInRange()
{
	if (!PlayerCharacter)
		return false;
	return (FVector::Dist(GetActorLocation(), PlayerCharacter->GetActorLocation()) <= TurretRange);
}
