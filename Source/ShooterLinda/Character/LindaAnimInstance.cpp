// Fill out your copyright notice in the Description page of Project Settings.


#include "LindaAnimInstance.h"
#include "LindaCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

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
    bWeaponEquipped = LindaCharacter->IsWeaponEquipped();
    isFiring = LindaCharacter->GetFiring();
}
