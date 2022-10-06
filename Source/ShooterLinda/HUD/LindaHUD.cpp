// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaHUD.h"
#include "GameFramework/PlayerController.h"
#include "CharacterOverlayWidget.h"
void ALindaHUD::BeginPlay() 
{
    Super::BeginPlay();
    AddCharacterOverlay();

}
void ALindaHUD::AddCharacterOverlay()
{
   APlayerController* PlayerController = GetOwningPlayerController();
   if(PlayerController && CharacterOverlayClass)
   {
        CharacterOverlayWidget = CreateWidget<UCharacterOverlayWidget>(PlayerController,CharacterOverlayClass);
        CharacterOverlayWidget->AddToViewport();
   }
}


void ALindaHUD::DrawHUD()
{
    Super::DrawHUD();

}