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
	int Dir=-1;  
	int GetDirection();
protected: 
	virtual void BeginPlay() override; 
	UPROPERTY(EditAnywhere)
	class UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* DieMontage;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float MaxHealth = 40.f;
	UPROPERTY(VisibleAnywhere, Category = "Player Stats")
	float Health = 40.f; 
	bool bDead = false;
 
	FTimerHandle DieTimer;
	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float DieDelay = 1.f;
	void DieTimerFinished();
 

public:	 
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
 
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
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void EquipWeapon(class AWeapon* WeaponToEquip);

	FTimerHandle TimerHandle;
	float  MaxTime=2;

	FTimerHandle TimerEquip;
	float  delayTime=3;

	FORCEINLINE bool IsDead() const{return bDead;};
	UPROPERTY(BlueprintReadWrite, Category = Movement, meta =(AllowPrivateAccess = "true"))
	class AWeapon* EnemyWeapon;  
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void EquipBPWeapon(USceneComponent* obj);

};
