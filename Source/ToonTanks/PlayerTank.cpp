// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#define OUT
APlayerTank::APlayerTank()
{
	PrimaryActorTick.bCanEverTick = true;
	TankCameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	CameraComponent->SetupAttachment(TankCameraArm);
	TankCameraArm->SetupAttachment(BaseMesh);
}
void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APlayerTank::Move(float Value)
{
	AddActorLocalOffset(FVector(Value * TankSpeed * UGameplayStatics::GetWorldDeltaSeconds(this), 0.f, 0.f), true);
	GetController();
}
void APlayerTank::Turn(float Value)
{
	FRotator DeltaRotation = FRotator::ZeroRotator;
	DeltaRotation.Yaw = Value * TurretTraversal * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalRotation(DeltaRotation, true);
}
void APlayerTank::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APlayerTank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APlayerTank::Turn);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &APlayerTank::Fire);
}
void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerControllerRef)
	{
		FHitResult LineTraceResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, OUT LineTraceResult);
		DrawDebugSphere(GetWorld(), LineTraceResult.ImpactPoint, 20.f, 12, FColor(255, 36, 0));
		RotateTurret(LineTraceResult.ImpactPoint);
	}
}
void APlayerTank::Fire()
{
	Super::Fire();
}