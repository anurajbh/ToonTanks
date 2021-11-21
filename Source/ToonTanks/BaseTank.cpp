// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTank.h"
#include "Components/CapsuleComponent.h"
#include "Bullet.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
ABaseTank::ABaseTank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleCollider"));
	RootComponent = CapsuleComp;
	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(RootComponent);
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("ProjectileSpawnPoint"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}
//visual/sound effects when actor dies
void ABaseTank::HandleDestruction()
{
	if (DeathTrail)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathTrail, GetActorLocation(), GetActorRotation());
	}
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
}
// Called when the game starts or when spawned
void ABaseTank::BeginPlay()
{
	Super::BeginPlay();
}
void ABaseTank::RotateTurret(FVector LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TurretMesh->GetComponentLocation();
	FRotator LookAtRotation = FRotator(0.f, ToTarget.Rotation().Yaw, 0.f);
	TurretMesh->SetWorldRotation(LookAtRotation);
}
void ABaseTank::Fire()
{
	ABullet* SpawnedProjectile = GetWorld()->SpawnActor<ABullet>(BulletClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	SpawnedProjectile->SetOwner(this);
}