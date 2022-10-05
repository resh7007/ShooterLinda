// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemies.generated.h"

UCLASS()

class SHOOTERLINDA_API AEnemies : public ACharacter
{
	GENERATED_BODY()

public: 
	AEnemies(); 
protected: 
	virtual void BeginPlay() override;

	int Dir=-1;  
	void test();
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

	FTimerHandle FuzeTimerHandle;
	float  MaxFuzeTime=2;
};
