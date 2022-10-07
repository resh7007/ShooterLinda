// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h" 
#include "ButtonWidget.generated.h"


/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API UButtonWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta = (BindWidget))
	class UButton* Btn;
 
	void SetData();

	UFUNCTION()
	void OnBtnClick();

	FORCEINLINE UButton* GetRestartBtn() const{return Btn;}

};
