// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseTank.h"
#include "PlayerTank.generated.h"

/**
 *
 */
UCLASS()
class TOONTANKS_API APlayerTank : public ABaseTank
{
	GENERATED_BODY()
public:
	APlayerTank();
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void HandleDestruction();
	APlayerController* GetTankPlayerController() const 
	{
		return TankPlayerController;
	}
	bool bIsAlive = true;
private:
	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers")
		class USpringArmComponent* TankCameraArm;
	UPROPERTY(VisibleAnywhere, Category = "ComponentPointers")
		class UCameraComponent* CameraComponent;
	void Move(float Value);
	void Turn(float Value);
	virtual void Fire() override;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float TankSpeed = 10.f;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float TurretTraversal = 10.f;
	APlayerController* TankPlayerController;
};
