// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LindaHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ALindaHUD : public AHUD
{
	GENERATED_BODY()
public:
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, Category = "Player Stats")
	TSubclassOf<class UUserWidget> CharacterOverlayClass;

	class UCharacterOverlayWidget* CharacterOverlayWidget;
protected:
	virtual void BeginPlay() override;
	void AddCharacterOverlay();

};
