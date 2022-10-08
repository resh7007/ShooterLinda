// Fill out your copyright notice in the Description page of Project Settings.


#include "Soldier.h"

ASoldier::ASoldier()
{ 
	PrimaryActorTick.bCanEverTick = false;   

}

 
void ASoldier::BeginPlay()
{
	Super::BeginPlay();    

}
 
 void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveRight(GetMoveDirection()*.1f);
}


int ASoldier::GetMoveDirection()
{
	FVector locaction = GetActorLocation(); 
	if(locaction.Y>250)
		MoveDirection=1;
	if(locaction.Y<-250)
		MoveDirection=-1;
	return MoveDirection;
}
  

void ASoldier::MoveRight(float Value)
{
	const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
	AddMovementInput(Direction, Value);
}
