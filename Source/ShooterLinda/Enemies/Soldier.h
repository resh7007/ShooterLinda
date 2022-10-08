// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies.h"
#include "Soldier.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ASoldier : public AEnemies
{
	GENERATED_BODY()
public:
	ASoldier();
protected:
	void MoveRight(); 
	virtual void BeginPlay() override;
private:
	int MoveDirection=-1;  
	int GetMoveDirection();

	FTimerHandle MoveTimer;   

public:
	virtual void Tick(float DeltaTime) override;

};
