// Fill out your copyright notice in the Description page of Project Settings.


#include "Soldier.h"

 void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveRight(GetDirection()*.1f);
}
void ASoldier::MoveRight(float Value)
{
	const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
	AddMovementInput(Direction, Value);
}
