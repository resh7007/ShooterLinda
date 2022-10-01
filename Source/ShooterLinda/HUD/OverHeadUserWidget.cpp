// Fill out your copyright notice in the Description page of Project Settings.


#include "OverHeadUserWidget.h"
#include "Components/TextBlock.h" 

void UOverHeadUserWidget::SetDisplayText(FString TextToDisplay)
{
    if(DisplayText)
    {
        DisplayText->SetText(FText::FromString(TextToDisplay));
    }
}
