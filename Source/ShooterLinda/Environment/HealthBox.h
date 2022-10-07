// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthBox.generated.h"

UCLASS()
class SHOOTERLINDA_API AHealthBox : public AActor
{
	GENERATED_BODY()
	
public:	 
	AHealthBox();

protected: 
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnSphereOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);
private:

	UPROPERTY(VisibleAnywhere, Category = "HealthBox Properties")
	class USphereComponent* AreaSphere;
	UPROPERTY(EditAnywhere, Category = "HealthBox Properties")
	float HealAmount=25.f;
public:	 
	virtual void Tick(float DeltaTime) override;

};
