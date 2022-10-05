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
private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* ProjectileMovementComponent;
	
	UPROPERTY(EditAnywhere)
	class UParticleSystem* Tracer;

	class UParticleSystemComponent* TracerComponent;
public:	 

};
