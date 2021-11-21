/// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "GameFramework/ProjectileMovementComponent.h"
// Sets default values
ABullet::ABullet()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletMesh");
	RootComponent = BulletMesh;
	BulletProjectile = CreateDefaultSubobject<UProjectileMovementComponent>("BulletProjectile");
	BulletProjectile->InitialSpeed = InitSpeed;
	BulletProjectile->MaxSpeed = MaxSpeed;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	BulletMesh->OnComponentHit.AddDynamic(this, &ABullet::OnHit);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABullet::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *HitComp->GetName());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetName());
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherComp->GetName());
}

