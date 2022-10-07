// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"
#include "CharacterOverlayWidget.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API UCharacterOverlayWidget : public UUserWidget
{
	GENERATED_BODY()
public: 
	virtual void NativeConstruct() override;
	UPROPERTY(meta  = (BindWidget))
	class UProgressBar* HealthBar;

	UPROPERTY(meta  = (BindWidget))
	class UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget))
	class UVerticalBox* VerticalBox;
 
	void ShowRestartBtn();

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UButtonWidget> ButtonWidgetRef; 
};
