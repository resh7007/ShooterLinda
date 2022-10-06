// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LindaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ALindaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void SetHUDHealth(float Health, float MaxHealth);
protected:
	virtual void BeginPlay() override;
private:
	class ALindaHUD* LindaHUD;
 
};
