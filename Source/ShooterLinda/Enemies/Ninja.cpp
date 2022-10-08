// Fill out your copyright notice in the Description page of Project Settings.


#include "Ninja.h"
ANinja::ANinja()
{ 
	PrimaryActorTick.bCanEverTick = false; 
}

 
void ANinja::BeginPlay()
{
	Super::BeginPlay();    
	GetWorldTimerManager().SetTimer(MoveTimer, this,&ANinja::MoveForward,.05f,true);

}
 

 void ANinja::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
}

void ANinja::MoveForward()
{
	FVector CurrentLocation = this->GetActorLocation(); 
  	CurrentLocation.X -= 2; 
    SetActorLocation(CurrentLocation); 
 
}


	 