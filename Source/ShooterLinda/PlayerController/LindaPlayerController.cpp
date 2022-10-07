// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaPlayerController.h"
#include "ShooterLinda/HUD/LindaHUD.h"
#include "ShooterLinda/HUD/CharacterOverlayWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "ShooterLinda/Character/LindaCharacter.h"
 

void ALindaPlayerController::BeginPlay()
{
    Super::BeginPlay();
    LindaHUD = Cast<ALindaHUD>(GetHUD());
}

void ALindaPlayerController::SetHUDHealth(float Health, float MaxHealth)
{
    LindaHUD = LindaHUD == nullptr ? Cast<ALindaHUD>(GetHUD()) : LindaHUD;
    bool bHUDValid = LindaHUD && LindaHUD->CharacterOverlayWidget && LindaHUD->CharacterOverlayWidget->HealthBar && LindaHUD->CharacterOverlayWidget->HealthText;
 
    if(bHUDValid)
    {
        const float HealthPercent = Health/MaxHealth;
        LindaHUD->CharacterOverlayWidget->HealthBar->SetPercent(HealthPercent);
        FString HealthText = FString::Printf(TEXT("%d/%d"), FMath::CeilToInt(Health), FMath::CeilToInt(MaxHealth));
        LindaHUD->CharacterOverlayWidget->HealthText->SetText(FText::FromString(HealthText));
	}

  

}
void ALindaPlayerController::ShowRestartBtn()
{
    LindaHUD = LindaHUD == nullptr ? Cast<ALindaHUD>(GetHUD()) : LindaHUD;
    bool bHUDValid = LindaHUD && LindaHUD->CharacterOverlayWidget && LindaHUD->CharacterOverlayWidget->VerticalBox;
 
    if(bHUDValid)
    { 
        LindaHUD->CharacterOverlayWidget->ShowRestartBtn();
	}

  

}