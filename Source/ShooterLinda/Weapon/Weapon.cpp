// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "ShooterLinda/Character/LindaCharacter.h"
#include "Animation/AnimationAsset.h"
#include "ShooterLinda/Enemies/Enemies.h"
#include "Components/SkeletalMeshComponent.h"
AWeapon::AWeapon()
{ 
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	SetRootComponent(WeaponMesh);

	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaShpere"));
	AreaSphere->SetupAttachment(RootComponent);
	AreaSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
 
	AreaSphere->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);  

	isCollisionOn = true;
} 
 
void AWeapon::BeginPlay()
{
	Super::BeginPlay(); 
	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnSphereOverlap); 
  
}
 
 
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor,UPrimitiveComponent* OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult& SweepResult)
{ 
	
 	if(!isCollisionOn) return;
	ALindaCharacter* LindaCharacter = Cast<ALindaCharacter> (OtherActor);
	if(LindaCharacter)
	{   
		LindaCharacter->SetOverlappingWeapon(this); 
		isCollisionOn =false; 

	} 

	AEnemies* EnemyCharacter = Cast<AEnemies> (OtherActor);
	if(EnemyCharacter)
	{    
		EnemyCharacter->SetOverlappingWeapon(this); 
		isCollisionOn =false; 
		UE_LOG(LogTemp, Warning, TEXT("weapon touching enemy") );

	} 

} 


void AWeapon::Fire(int shootDir)
{ 
	if(FireAnimation)
	{
		WeaponMesh->PlayAnimation(FireAnimation,false);
	}
}
 