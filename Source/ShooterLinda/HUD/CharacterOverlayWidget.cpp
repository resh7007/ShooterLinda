// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterOverlayWidget.h"
#include "Components/Button.h"
#include "ButtonWidget.h"
#include "Math/Color.h"
#include "Blueprint/UserWidget.h"



void UCharacterOverlayWidget::NativeConstruct()
{
    Super::NativeConstruct();
  
}

void UCharacterOverlayWidget::ShowRestartBtn()
{ 

    if(ButtonWidgetRef)
    {
        UUserWidget* widget = CreateWidget(this, ButtonWidgetRef);
        VerticalBox->AddChildToVerticalBox(widget);
        UButtonWidget* button = Cast<UButtonWidget>(widget);
        button->GetRestartBtn()->SetBackgroundColor(FLinearColor(0,1,0,1));
        button->SetData(); 

    }
}
