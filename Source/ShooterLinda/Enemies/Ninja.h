// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemies.h"
#include "Ninja.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ANinja : public AEnemies
{
	GENERATED_BODY()
protected:
	virtual void MoveForward(float Value); 
public:
	virtual void Tick(float DeltaTime) override;
};
