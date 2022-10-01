// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies.h"

// Sets default values
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
	MoveForward(1);
}
 
void AEnemies::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemies::MoveForward(float Value)
{
 
	//if(Value != 0.f)
	//{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	//}
}
void AEnemies::MoveRight(float Value)
{
	if(Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}
