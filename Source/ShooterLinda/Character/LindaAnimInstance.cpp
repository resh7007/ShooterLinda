// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaAnimInstance.h"
#include "LindaCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ShooterLinda/Weapon/Weapon.h"
void ULindaAnimInstance::NativeInitializeAnimation() 
{
    Super::NativeInitializeAnimation();

    LindaCharacter = Cast<ALindaCharacter>(TryGetPawnOwner());
}
void ULindaAnimInstance::NativeUpdateAnimation(float DeltaTime) 
{
    Super::NativeUpdateAnimation(DeltaTime);

    if(LindaCharacter == nullptr)
    {
      LindaCharacter = Cast<ALindaCharacter>(TryGetPawnOwner());
    }
    if(LindaCharacter == nullptr) return;

    FVector Velocity = LindaCharacter->GetVelocity();
    Velocity.Z = 0.f;
    Speed =  Velocity.Size();
 

    bIsInAir = LindaCharacter->GetCharacterMovement()->IsFalling();
    bIsAccelerating = LindaCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;
    isFiring = LindaCharacter->GetFiring();

    bWeaponEquipped = LindaCharacter->IsWeaponEquipped();
    EquippedWeapon = LindaCharacter->GetEquippedWeapon();

    if(bWeaponEquipped && EquippedWeapon && EquippedWeapon->GetWeaponMesh() && LindaCharacter->GetMesh())
    {
      
      LeftHandTransform = EquippedWeapon->GetWeaponMesh()->GetSocketTransform(FName("LeftHandSocket"), ERelativeTransformSpace::RTS_World);
      FVector OutPosition;
      FRotator OutRotation;

      LindaCharacter->GetMesh()->TransformToBoneSpace(FName("RightHand"), LeftHandTransform.GetLocation(),FRotator::ZeroRotator,OutPosition,OutRotation);
      LeftHandTransform.SetLocation(OutPosition);
      LeftHandTransform.SetRotation(FQuat(OutRotation));

    }
}
