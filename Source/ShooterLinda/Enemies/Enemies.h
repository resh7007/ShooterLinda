// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemies.generated.h"

#define TRACE_LENGTH 80000.f

UCLASS()

class SHOOTERLINDA_API AEnemies : public ACharacter
{
	GENERATED_BODY()

public: 
	AEnemies(); 
	void PlayHitReactMontage();
	void PlayDieMontage();
	void Die();
	void ReceiveDamage(float Damage);
protected: 
	virtual void BeginPlay() override;
	void TraceUnderCrosshairs();

	int Dir=-1;  
	void test();


	UPROPERTY(EditAnywhere)
	class UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* DieMontage;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float MaxHealth = 40.f;
	UPROPERTY(VisibleAnywhere, Category = "Player Stats")
	float Health = 40.f; 
	bool bDead = false;
 


private:
	FVector HitTarget;

public:	 
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
 
	int GetDirection();
	class AWeapon* EquippedWeapon;
	AWeapon* GetEquippedWeapon();
	
	UPROPERTY(VisibleDefaultsOnly)
    class UChildActorComponent* Weapon1;


	UPROPERTY(VisibleAnywhere, Category = "Base Character")
    TSubclassOf<class AWeapon> WeaponClass;

	UFUNCTION()
	void Shoot();

	class AWeapon* OverlappingWeapon;
	void SetOverlappingWeapon(AWeapon* Weapon);
	void EquipWeapon(class AWeapon* WeaponToEquip);

	FTimerHandle TimerHandle;
	float  MaxTime=2;
	FORCEINLINE bool IsDead() const{return bDead;};

};
