// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "Projectile.generated.h"

UCLASS()
class SHOOTERLINDA_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	 
	AProjectile();
	virtual void Tick(float DeltaTime) override;

protected: 
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* Tracer;

	class UParticleSystemComponent* TracerComponent;
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* ImpactParticles;

	UPROPERTY(EditAnywhere)
	class USoundCue* ImpactSound;

	UPROPERTY(EditAnywhere)
	float Damage =20.f;
 
private:
	FTimerHandle DieTimer;
	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float DieDelay = 15.f;
	void DieTimerFinished();
public:	 

};
