// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies.h"
#include "GameFramework/Actor.h" 
#include "ShooterLinda/Weapon/Weapon.h" 
#include "Engine/SkeletalMeshSocket.h" 

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
	//UE_LOG(LogTemp, Warning, TEXT("my pos=, %s"), *locaction.ToString() );

	if(locaction.Y>250)
		Dir=1;
	if(locaction.Y<-250)
		Dir=-1;

	return Dir;
}
 
 
 