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
protected:
	void MoveRight(float Value); 
public:
	virtual void Tick(float DeltaTime) override;

};
