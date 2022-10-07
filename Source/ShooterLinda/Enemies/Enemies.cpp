// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies.h"
#include "GameFramework/Actor.h" 
#include "ShooterLinda/Weapon/Weapon.h" 
#include "Engine/SkeletalMeshSocket.h" 
#include "Kismet/GameplayStatics.h"
#include "ShooterLinda/ShooterLindaGameModeBase.h"
#include "TimerManager.h"
AEnemies::AEnemies()
{ 
	PrimaryActorTick.bCanEverTick = true;   
}
 
void AEnemies::BeginPlay()
{
	Super::BeginPlay();  
}
 
void AEnemies::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
 	TraceUnderCrosshairs();
}
 
void AEnemies::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

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

 
void AEnemies::SetOverlappingWeapon(AWeapon* weapon)
{ 
	OverlappingWeapon = weapon;
	EquipWeapon(OverlappingWeapon);
	Shoot();
}

 
void AEnemies::Shoot()
{
	if(EquippedWeapon)
	EquippedWeapon->Fire(HitTarget);
 
  	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AEnemies::Shoot, MaxTime, false);

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


void AEnemies::TraceUnderCrosshairs()
{
	HitTarget = GetOwner()->GetActorLocation();  
	
}


void AEnemies::PlayHitReactMontage()
{ 
	 
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(AnimInstance && HitReactMontage)
	{
		AnimInstance->Montage_Play(HitReactMontage); 
	}

}

void AEnemies::PlayDieMontage()
{  
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(AnimInstance && DieMontage)
	{
		AnimInstance->Montage_Play(DieMontage); 
	}

}
void AEnemies::Die()
{
	bDead = true;
	PlayDieMontage();
  

	GetWorldTimerManager().SetTimer(DieTimer, this,&AEnemies::DieTimerFinished,DieDelay);
}
void AEnemies::ReceiveDamage(float Damage)
{
	Health = FMath::Clamp(Health-Damage,0.f,MaxHealth); 
	if(Health == 0.f)
	{
		AShooterLindaGameModeBase* ShooterLindaGameModeBase = GetWorld()->GetAuthGameMode<AShooterLindaGameModeBase>();
		if(ShooterLindaGameModeBase)
		{ 
			ShooterLindaGameModeBase->EnemyEliminated(this);
		} 
	}
}
void AEnemies::DieTimerFinished()
{
	AShooterLindaGameModeBase* ShooterLindaGameModeBase = GetWorld()->GetAuthGameMode<AShooterLindaGameModeBase>();
	if(ShooterLindaGameModeBase)
		{
			 ShooterLindaGameModeBase->DestroyEnemy(this);
		}
}

 