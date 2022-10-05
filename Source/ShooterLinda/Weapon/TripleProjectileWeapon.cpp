// Fill out your copyright notice in the Description page of Project Settings.


#include "TripleProjectileWeapon.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Projectile.h"

void ATripleProjectileWeapon::Fire(const FVector& HitTarget) 
{
    Super::Fire(HitTarget);

    APawn* InstigatorPawn = Cast<APawn>(GetOwner());
    const USkeletalMeshSocket* MuzzleFlashSocket = GetWeaponMesh()->GetSocketByName(FName("MuzzleFlash"));
    if(MuzzleFlashSocket)
    {
        FTransform SocketTransform = MuzzleFlashSocket->GetSocketTransform(GetWeaponMesh());

        FVector ToTarget =  SocketTransform.GetLocation() - HitTarget;
        ToTarget.Z=0;
        ToTarget.Y=-10;
        SpawnProjectile(ToTarget,InstigatorPawn,SocketTransform);
        ToTarget.Y=0;
        SpawnProjectile(ToTarget,InstigatorPawn,SocketTransform);
        ToTarget.Y=10;
        SpawnProjectile(ToTarget,InstigatorPawn,SocketTransform);
    }

}

void ATripleProjectileWeapon::SpawnProjectile(FVector ToTarget, APawn* InstigatorPawn, FTransform SocketTransform)
{
    FRotator TargetRotation = ToTarget.Rotation();
        if(ProjectileClass && InstigatorPawn)
        {
            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = GetOwner();
            SpawnParams.Instigator = InstigatorPawn;
            UWorld* World = GetWorld();
            if(World)
            {
                World->SpawnActor<AProjectile>(
                    ProjectileClass,
                    SocketTransform.GetLocation(),
                    TargetRotation,
                    SpawnParams
                );
            }
        }
}
