// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies.h"
#include "GameFramework/Actor.h" 
#include "ShooterLinda/Weapon/Weapon.h" 
#include "Engine/SkeletalMeshSocket.h" 

AEnemies::AEnemies()
{ 
	PrimaryActorTick.bCanEverTick = true;  
	// Weapon1 = CreateDefaultSubobject<UChildActorComponent>(TEXT("PlayerWeapon"));
    // Weapon1->SetChildActorClass(WeaponClass);
    // Weapon1->CreateChildActor();
	// Weapon1->SetupAttachment(GetMesh(),FName("RightHandSocket"));
 	// Weapon = ((AWeapon *)Weapon1->GetChildActor());
}
 
void AEnemies::BeginPlay()
{
	Super::BeginPlay();  
}
 
void AEnemies::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MoveForward(.1f);
	MoveRight(GetDirection()*.1f);
 
}
 
void AEnemies::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemies::MoveForward(float Value)
{
	const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
	AddMovementInput(Direction, Value);
	 
}
void AEnemies::MoveRight(float Value)
{
	const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
	AddMovementInput(Direction, Value);
}

int AEnemies::GetDirection()
{
	FVector locaction = GetActorLocation(); 
	if(locaction.Y>250)
		Dir=1;
	if(locaction.Y<-250)
		Dir=-1;

	return Dir;
}
  
AWeapon* AEnemies::GetEquippedWeapon()
{   
	return EquippedWeapon;
}
 
void AEnemies::Shoot()
{
	if(EquippedWeapon)
	EquippedWeapon->Fire();

	 /* Activate the fuze to explode the bomb after several seconds */
  GetWorld()->GetTimerManager().SetTimer(FuzeTimerHandle, this, &AEnemies::Shoot, MaxFuzeTime, false);

}
 
void AEnemies::SetOverlappingWeapon(AWeapon* weapon)
{ 
	OverlappingWeapon = weapon;
	EquipWeapon(OverlappingWeapon);
	Shoot();
}
void AEnemies::EquipWeapon(class AWeapon* WeaponToEquip)
{
	if(WeaponToEquip == nullptr) return;

	EquippedWeapon = WeaponToEquip;
	EquippedWeapon->SetWeaponState(EWeaponState::EWS_Equipped); 

	const USkeletalMeshSocket* HandSocket = GetMesh()->GetSocketByName(FName("RightHandSocket"));

	if(HandSocket)
	{
		HandSocket->AttachActor(EquippedWeapon,GetMesh());
	}

	EquippedWeapon->SetOwner(this); 

}