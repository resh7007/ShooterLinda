// Fill out your copyright notice in the Description page of Project Settings.


#include "Ninja.h"
ANinja::ANinja()
{ 
	PrimaryActorTick.bCanEverTick = true;    

}


 void ANinja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(.01f);
}

void ANinja::MoveForward(float Value)
{
	const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
	AddMovementInput(Direction, Value);
	 
}


	 