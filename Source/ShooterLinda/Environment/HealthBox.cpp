// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBox.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ShooterLinda/Character/LindaCharacter.h"
// Sets default values
AHealthBox::AHealthBox()
{ 
	PrimaryActorTick.bCanEverTick = false;

	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaShpere"));
	AreaSphere->SetupAttachment(RootComponent);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);  

}
 
void AHealthBox::BeginPlay()
{
	Super::BeginPlay();
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &AHealthBox::OnSphereOverlap); 
	
}
 
void AHealthBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHealthBox::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult& SweepResult)
{ 
	 
	ALindaCharacter* LindaCharacter = Cast<ALindaCharacter> (OtherActor);
	if(LindaCharacter)
	{   
		LindaCharacter->SetOverlappingHealthBox(HealAmount);  
		Destroy(this);
	}
} 
