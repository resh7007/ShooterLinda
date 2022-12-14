// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equipped UMETA(DisplayName = "Equipped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX"),


};
UCLASS()
class SHOOTERLINDA_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	 
	AWeapon();
	virtual void Tick(float DeltaTime) override; 
	void GetTheOwner();
	virtual void Fire(int shootDir);
	
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
	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(VisibleAnywhere, Category = "Weapon Properties")
	class USphereComponent* AreaSphere;

	UPROPERTY(VisibleAnywhere)
	EWeaponState WeaponState; 
	bool isCollisionOn;
	UPROPERTY(EditAnywhere)
	class UAnimationAsset* FireAnimation; 
public:	 

	FORCEINLINE void SetWeaponState(EWeaponState State) {WeaponState = State;}
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh() const{return  WeaponMesh;}

};
