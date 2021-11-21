// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseTank.generated.h"

UCLASS()
class TOONTANKS_API ABaseTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Combat")
		float TurretRange = 100.f;
	virtual void Fire();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PawnHealth = 100.f;
	void HandleDestruction();

protected:
	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent* CapsuleComp = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		TSubclassOf<class ABullet> BulletClass;
	UPROPERTY(EditAnywhere, Category = "Combat")
		class UParticleSystem* DeathTrail;
	void RotateTurret(FVector LookAtTarget);
	UPROPERTY(EditAnywhere, Category = "Combat")
		class USoundBase* DeathSound;
};
