// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "ShooterLinda/Weapon/Weapon.h" 
#include "ShooterLinda/Character/LindaCharacter.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Kismet/GameplayStatics.h"
UCombatComponent::UCombatComponent()
{
 
	PrimaryComponentTick.bCanEverTick = true;
 
}

 
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}

 
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
 	TraceUnderCrosshairs();
}

void UCombatComponent::EquipWeapon(class AWeapon* WeaponToEquip)
{
	if(Character ==nullptr || WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped); 

	const USkeletalMeshSocket* HandSocket = Character->GetMesh()->GetSocketByName(FName("RightHandSocket"));

	if(HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon, Character->GetMesh());
	}

	EquippedWeapon->SetOwner(Character); 
}


void UCombatComponent::FireButtonPressed(bool bPressed)
{
	bFireButtonPressed = bPressed;
	if(EquippedWeapon == nullptr) return;
	EquippedWeapon->Fire(HitTarget);

}
void UCombatComponent::TraceUnderCrosshairs()
{
 
	HitTarget = GetOwner()->GetActorLocation();
	
}
void UCombatComponent::DestroyWeapon()
{
	if(EquippedWeapon)
	{
		EquippedWeapon->Destroy();
	}
}
