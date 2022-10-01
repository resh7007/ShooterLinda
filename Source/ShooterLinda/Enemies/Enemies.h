// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemies.generated.h"

UCLASS()
class SHOOTERLINDA_API AEnemies : public ACharacter
{
	GENERATED_BODY()

public: 
	AEnemies();

protected: 
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
public:	 
	virtual void Tick(float DeltaTime) override;
 
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
