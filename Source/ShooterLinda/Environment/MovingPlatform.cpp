// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "GameFramework/Actor.h" 
AMovingPlatform::AMovingPlatform()
{ 
	PrimaryActorTick.bCanEverTick = true; 

}
 
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}
 
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Move();
}

void AMovingPlatform::Move()
{
	FVector locaction = GetActorLocation();
	locaction.X-=10;
	SetActorLocation(locaction);
}

