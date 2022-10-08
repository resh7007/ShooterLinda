// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "GameFramework/Actor.h" 
#include "HealthBox.h"
#include "ShooterLinda/Enemies/Enemies.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

AMovingPlatform::AMovingPlatform()
{ 
	PrimaryActorTick.bCanEverTick = true; 

}
 
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	SpawnHealthBox();
	SpawnSoldierEnemy();
	SpawnNinjaEnemy();
}
 
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
}
void AMovingPlatform::SpawnHealthBox()
{
	UWorld* world=GetWorld();
	if(world)
	{
		FVector playerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();
		FVector healthBoxLocation = playerLocation;

		float randomDistanceX = FMath::RandRange(990.f, 1200.f);
		healthBoxLocation.X += randomDistanceX; 

		float randomDistanceY = FMath::RandRange(-400.f, 400.f);
		healthBoxLocation.Y = randomDistanceY; 


		world->SpawnActor<AHealthBox>(HealthBoxBlueprint, healthBoxLocation, FRotator::ZeroRotator);
	}
}
 
void AMovingPlatform::SpawnSoldierEnemy()
{
	UWorld* world=GetWorld();
	if(world)
	{
		FVector playerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();
		FVector enemyLocation = playerLocation;

		float randomDistanceX = FMath::RandRange(1220.f, 1500.f);
		enemyLocation.X += randomDistanceX; 

		float randomDistanceY = FMath::RandRange(-400.f, 400.f);
		enemyLocation.Y = randomDistanceY;  

		world->SpawnActor<AEnemies>(SoldierBlueprint, enemyLocation, FRotator(0.f,180.0f,0.f)); 
		 
	}
}
 
 void AMovingPlatform::SpawnNinjaEnemy()
{
	UWorld* world=GetWorld();
	if(world)
	{
		FVector playerLocation = UGameplayStatics::GetPlayerCharacter(world, 0)->GetActorLocation();
		FVector enemyLocation = playerLocation;

		float randomDistanceX = FMath::RandRange(1220.f, 1500.f);
		enemyLocation.X += randomDistanceX; 

		float randomDistanceY = FMath::RandRange(-400.f, 400.f);
		enemyLocation.Y = randomDistanceY;  

		world->SpawnActor<AEnemies>(NinjaBlueprint, enemyLocation, FRotator(0.f,180.0f,0.f)); 
		 
	}
}
 
 