// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTank.h"
#include "EnemyTurret.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API AEnemyTurret : public ABaseTank
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	class APlayerTank* PlayerCharacter;
	APawn* PlayerPawn;
	struct FTimerHandle EnemyTimerHandle;
	float FireRate = 2.f;
	void CheckForFiring();
	bool CheckIfPlayerIsInRange();
};
