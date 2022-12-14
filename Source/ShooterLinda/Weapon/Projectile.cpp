// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "ShooterLinda/Character/LindaCharacter.h"
#include "ShooterLinda/Enemies/Enemies.h" 
#include "GameFramework/Character.h"
#include "TimerManager.h"
AProjectile::AProjectile()
{ 
	PrimaryActorTick.bCanEverTick = true;
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	SetRootComponent(CollisionBox); 
	CollisionBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility,ECollisionResponse::ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldStatic,ECollisionResponse::ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Block); 

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->bRotationFollowsVelocity=true;
 
}
 
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	if(Tracer)
	{
		TracerComponent = UGameplayStatics::SpawnEmitterAttached(
			Tracer,
			CollisionBox,
			FName(),
			GetActorLocation(),
			GetActorRotation(),
			EAttachLocation::KeepWorldPosition
		);
	}

	CollisionBox->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	GetWorldTimerManager().SetTimer(DieTimer, this,&AProjectile::DieTimerFinished,DieDelay);

}

void AProjectile::DieTimerFinished()
{
	this->Destroy();
}
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(ImpactParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, GetActorTransform());

	}
	if(ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
 
	ALindaCharacter* LindaCharacter = Cast<ALindaCharacter>(OtherActor);
	if(LindaCharacter)
	{
		LindaCharacter->PlayHitReactMontage();
		LindaCharacter->ReceiveDamage(Damage);

	}


	AEnemies* EnemyCharacter = Cast<AEnemies>(OtherActor);
	if(EnemyCharacter)
	{
		AEnemies* enemyProjectile = Cast<AEnemies>(GetOwner());
		EnemyCharacter->PlayHitReactMontage();
		EnemyCharacter->ReceiveDamage(Damage);
	}
 
	Destroy();
}

