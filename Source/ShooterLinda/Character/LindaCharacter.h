// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LindaCharacter.generated.h"

UCLASS(Blueprintable)
class SHOOTERLINDA_API ALindaCharacter : public ACharacter
{
	GENERATED_BODY()

public: 
	ALindaCharacter(); 
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	void PlayHitReactMontage();
	void PlayDieMontage();
	void Die();
	void SetOverlappingHealthBox(float HealAmount);
protected: 
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipWeapon();
	void FireButtonPressed();
	void FireButtonReleased();
	UFUNCTION()
	void ReceiveDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* InstigatorController, AActor* DamageCauser);

private:
	UPROPERTY(VisibleAnywhere, Category = Camera)
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	class UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere)
	class UCombatComponent* Combat;
	bool IsFiring;

	UPROPERTY(EditAnywhere, Category = Combat)
	class UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere, Category = Combat)
	class UAnimMontage* DieMontage;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, Category = "Player Stats")
	float Health =100.f;
	class ALindaPlayerController* LindaPlayerController;
	bool bDead = false;
	void ReloadLevel();

	FTimerHandle RestartLevelTimer;
	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float RestartLevelDelay = 1.f; 

	FTimerHandle DieTimer;
	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float DieDelay = 1.f;
	void DieTimerFinished();
	
public:	
	void ShowRestartBtn();
	class AWeapon* OverlappingWeapon;
	void SetOverlappingWeapon(AWeapon* Weapon);

	bool IsWeaponEquipped(); 
	FORCEINLINE int GetFiring(){return IsFiring;};
	AWeapon* GetEquippedWeapon();
	UFUNCTION(BlueprintCallable)
	void UpdateHUD();

	FORCEINLINE bool IsDead() const{return bDead;};

};
