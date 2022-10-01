// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ShooterLinda/LindaComponents/CombatComponent.h"
#include "ShooterLinda/Weapon/Weapon.h"

ALindaCharacter::ALindaCharacter()
{ 
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera  = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	Combat = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	
}
 
void ALindaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}
void ALindaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &ALindaCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALindaCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ALindaCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ALindaCharacter::LookUp);
	PlayerInputComponent->BindAction("Equip",IE_Pressed, this, &ALindaCharacter::EquipButtonPressed);
}

void ALindaCharacter::PostInitializeComponents() 
{
	Super::PostInitializeComponents();
	if(Combat)
	{
		Combat->Character = this;
	}
}


void ALindaCharacter::MoveForward(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}
void ALindaCharacter::MoveRight(float Value)
{
	if(Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}
void ALindaCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}	
void ALindaCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ALindaCharacter::EquipButtonPressed()
{
	if(Combat)
	{
		Combat->EquipWeapon(OverlappingWeapon);
	}

}
 
void ALindaCharacter::SetOverlappingWeapon(AWeapon* Weapon)
{
	if (OverlappingWeapon)
	{
		OverlappingWeapon->ShowPickupWidget(false);
	}
	OverlappingWeapon = Weapon;
	 
}
void ALindaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(1);

}

