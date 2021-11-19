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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PawnHealth = 100.f;

private:
	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true" ))
	class UCapsuleComponent* CapsuleComp = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BaseMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* TurretMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint = nullptr;
};
