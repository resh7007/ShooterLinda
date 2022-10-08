// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "TripleProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ATripleProjectileWeapon : public AWeapon
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AProjectile> ProjectileClass;
	void SpawnProjectile(FVector ToTarget, APawn* InstigatorPawn, FTransform SocketTransform);
public:
	virtual void Fire(int shootDir) override;

};
