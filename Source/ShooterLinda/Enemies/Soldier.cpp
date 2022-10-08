// Fill out your copyright notice in the Description page of Project Settings.


#include "Soldier.h"

ASoldier::ASoldier()
{ 
	PrimaryActorTick.bCanEverTick = false;   

}

 
void ASoldier::BeginPlay()
{
	Super::BeginPlay();    
	GetWorldTimerManager().SetTimer(MoveTimer, this,&ASoldier::MoveRight,.05f,true);

}
 
 void ASoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}



void ASoldier::MoveRight()
{
	int dir = GetMoveDirection(); 
	FVector CurrentLocation = this->GetActorLocation(); 
  	CurrentLocation.Y -= 10*dir; 
    SetActorLocation(CurrentLocation); 
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
  