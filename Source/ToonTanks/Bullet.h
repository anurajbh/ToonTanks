// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TOONTANKS_API ABullet : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = "Combat", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* BulletMesh = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Combat", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UProjectileMovementComponent* BulletProjectile = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		float InitSpeed = 20.f;
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
		float MaxSpeed = 100.f;
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UPROPERTY(EditAnywhere, Category = "Combat")
		float Damage = 50.f;
};
