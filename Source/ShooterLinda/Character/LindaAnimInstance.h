// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LindaAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API ULindaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;

private:
	UPROPERTY(BlueprintReadOnly, Category = Character, meta =(AllowPrivateAccess = "true"))
	class ALindaCharacter* LindaCharacter; 

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Category = Movement, meta =(AllowPrivateAccess = "true"))
	bool bIsAccelerating;
};
