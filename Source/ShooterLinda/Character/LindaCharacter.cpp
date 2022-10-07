// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ShooterLinda/LindaComponents/CombatComponent.h"
#include "ShooterLinda/Weapon/Weapon.h"
#include "ShooterLinda/PlayerController/LindaPlayerController.h"
#include "ShooterLinda/ShooterLindaGameModeBase.h"

ALindaCharacter::ALindaCharacter()
{ 
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera  = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	Combat = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));

}
 
void ALindaCharacter::BeginPlay()
{
	Super::BeginPlay();
	UpdateHUD();
	OnTakeAnyDamage.AddDynamic(this, &ALindaCharacter::ReceiveDamage);
}
void ALindaCharacter::UpdateHUD()
{
	LindaPlayerController = LindaPlayerController==nullptr ? Cast<ALindaPlayerController>(Controller) : LindaPlayerController;
	if(LindaPlayerController)
	{
		LindaPlayerController->SetHUDHealth(Health, MaxHealth); 
	}
}
void ALindaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &ALindaCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ALindaCharacter::MoveRight);  

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ALindaCharacter::FireButtonPressed);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ALindaCharacter::FireButtonReleased);



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
 
void ALindaCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ALindaCharacter::EquipWeapon()
{
	if(Combat)
	{
		Combat->EquipWeapon(OverlappingWeapon);
	}

}
 
void ALindaCharacter::SetOverlappingWeapon(AWeapon* Weapon)
{ 
	OverlappingWeapon = Weapon;
	EquipWeapon();
}
void ALindaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveForward(.05f);

}

bool ALindaCharacter::IsWeaponEquipped()
{
	return (Combat && Combat->EquippedWeapon);
}

void ALindaCharacter::FireButtonPressed()
{ 
	if(Combat)
	{
		Combat->FireButtonPressed(true);
	}
	IsFiring=true;

}
void ALindaCharacter::FireButtonReleased()
{
	if(Combat)
	{
		Combat->FireButtonPressed(false);
	}
	IsFiring=false;

}
AWeapon*  ALindaCharacter::GetEquippedWeapon()
{
	if(Combat == nullptr) return nullptr;
	return Combat->EquippedWeapon;
}

void ALindaCharacter::PlayHitReactMontage()
{ 
	if(Combat==nullptr || Combat->EquippedWeapon==nullptr) return;
	
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(AnimInstance && HitReactMontage)
	{
		AnimInstance->Montage_Play(HitReactMontage);
		// FName SectionName("Default"); 
		// AnimInstance->Montage_JumpToSection(SectionName);
	}

}
 void ALindaCharacter::PlayDieMontage()
{ 
	if(Combat==nullptr || Combat->EquippedWeapon==nullptr) return;
	
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if(AnimInstance && DieMontage)
	{
		AnimInstance->Montage_Play(DieMontage); 
	}

}
void ALindaCharacter::Die()
{
	bDead = true;
	PlayDieMontage();
}
void ALindaCharacter::ReceiveDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, class AController* InstigatorController, AActor* DamageCauser)
{
	Health = FMath::Clamp(Health-Damage,0.f,MaxHealth);
	UpdateHUD();

	if(Health == 0.f)
	{
		AShooterLindaGameModeBase* ShooterLindaGameModeBase = GetWorld()->GetAuthGameMode<AShooterLindaGameModeBase>();
		if(ShooterLindaGameModeBase)
		{
			LindaPlayerController = LindaPlayerController==nullptr ? Cast<ALindaPlayerController>(Controller) :LindaPlayerController; 
			ShooterLindaGameModeBase->PlayerEliminated(this, LindaPlayerController);
		}
	}
}
 
