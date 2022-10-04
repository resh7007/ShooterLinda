// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API UEnemyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;
	class AWeapon* EquippedWeapon;
 
private:
	UPROPERTY(BlueprintReadOnly, Category = Character, meta =(AllowPrivateAccess = "true"))
	class AEnemies* Enemy; 
	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	bool bIsInRange;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	int GetDirection=1;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	FTransform LeftHandTransform;
};
