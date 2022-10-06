// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "Enemies.h"
#include "ShooterLinda/Weapon/Weapon.h" 
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

  GetDirection = Enemy->GetDirection();
 

  EquippedWeapon = Enemy->GetEquippedWeapon();

  if(EquippedWeapon && EquippedWeapon->GetWeaponMesh() && Enemy->GetMesh())
  { 
    LeftHandTransform = EquippedWeapon->GetWeaponMesh()->GetSocketTransform(FName("LeftHandSocket"), ERelativeTransformSpace::RTS_World);
    FVector OutPosition;
    FRotator OutRotation;

    Enemy->GetMesh()->TransformToBoneSpace(FName("RightHand"), LeftHandTransform.GetLocation(),FRotator::ZeroRotator,OutPosition,OutRotation);
    LeftHandTransform.SetLocation(OutPosition);
    LeftHandTransform.SetRotation(FQuat(OutRotation)); 
  } 

}



