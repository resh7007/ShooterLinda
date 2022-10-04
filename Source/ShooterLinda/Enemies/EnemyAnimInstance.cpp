// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "Enemies.h"
#include "GameFramework/CharacterMovementComponent.h"

void UEnemyAnimInstance::NativeInitializeAnimation() 
{
  Super::NativeInitializeAnimation();

  Enemy = Cast<AEnemies>(TryGetPawnOwner());

}
void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaTime) 
{
    Super::NativeUpdateAnimation(DeltaTime);

    if(Enemy == nullptr)
    {
      Enemy = Cast<AEnemies>(TryGetPawnOwner());
    }
    if(Enemy == nullptr) return;
 
    // bIsInAir = LindaCharacter->GetCharacterMovement()->IsFalling();
    // bIsAccelerating = LindaCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f ? true : false;

    GetDirection = Enemy->GetDirection();
}



