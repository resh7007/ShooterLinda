// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "MovingPlatform.generated.h"
UCLASS()
class SHOOTERLINDA_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	 
	AMovingPlatform(); 
protected: 
	virtual void BeginPlay() override;
private:
	void SpawnHealthBox();
	void SpawnEnemy();




public:	 
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AHealthBox> HealthBoxBlueprint;
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<class AActor> EnemyBlueprint;
};
