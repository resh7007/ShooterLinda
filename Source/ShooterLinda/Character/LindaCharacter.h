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
protected: 
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void EquipWeapon();
	void FireButtonPressed();
	void FireButtonReleased();


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

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	float MaxHealth = 100.f;
	UPROPERTY(VisibleAnywhere, Category = "Player Stats")
	float Health =100.f;
	class ALindaPlayerController* LindaPlayerController;

public:	

	class AWeapon* OverlappingWeapon;
	void SetOverlappingWeapon(AWeapon* Weapon);
	bool IsWeaponEquipped(); 
	FORCEINLINE int GetFiring(){return IsFiring;};
	AWeapon* GetEquippedWeapon();
	UFUNCTION(BlueprintCallable)
	void SetHUD();
};
