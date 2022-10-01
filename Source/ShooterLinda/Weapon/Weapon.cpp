// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "Components/SphereComponent.h"
 
AWeapon::AWeapon()
{ 
	PrimaryActorTick.bCanEverTick = false;
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);

	WeaponMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);
	WeaponMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Ignore);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaShpere"));
	AreaSphere->SetupAttachment(RootComponent);

	
}
 
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}
 
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

