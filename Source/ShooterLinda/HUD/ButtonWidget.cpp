// Fill out your copyright notice in the Description page of Project Settings.


#include "ButtonWidget.h"
#include "Kismet/GameplayStatics.h"


void UButtonWidget::SetData()
{ 
    Btn->OnClicked.AddDynamic(this, &UButtonWidget::OnBtnClick);
}
void UButtonWidget::OnBtnClick()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
     
}
 
 
