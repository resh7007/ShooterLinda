// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"

#define TRACE_LENGTH 80000.f
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTERLINDA_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	 
	UCombatComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	friend class ALindaCharacter;
	void EquipWeapon(class AWeapon* WeaponToEquip);
	void DestroyWeapon();
protected: 
	virtual void BeginPlay() override;
	void FireButtonPressed(bool bPressed); 
private:
	class ALindaCharacter* Character;
	AWeapon* EquippedWeapon;
	bool bFireButtonPressed;
 
public:	 

		
};
