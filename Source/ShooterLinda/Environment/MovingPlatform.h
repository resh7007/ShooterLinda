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
	// Sets default values for this actor's properties
	AMovingPlatform(); 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	void Move();



public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
