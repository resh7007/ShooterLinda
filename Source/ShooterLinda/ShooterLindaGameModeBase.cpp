// Copyright Epic Games, Inc. All Rights Reserved.


#include "ShooterLindaGameModeBase.h"
#include "ShooterLinda/Character/LindaCharacter.h"
#include "ShooterLinda/Enemies/Enemies.h"

#include "ShooterLinda/PlayerController/LindaPlayerController.h"


void AShooterLindaGameModeBase::PlayerEliminated(class ALindaCharacter* ElimmedCharacter, class ALindaPlayerController* VictimController)
{
    if(ElimmedCharacter)
    {
        ElimmedCharacter->Die();
    }
}

void AShooterLindaGameModeBase::EnemyEliminated(class AEnemies* ElimmedEnemy)
{
 if(ElimmedEnemy)
    {
        ElimmedEnemy->Die();
    }
}

void AShooterLindaGameModeBase::DestroyEnemy(AEnemies* ElimmedEnemy)
{
    if(ElimmedEnemy)
    {
        ElimmedEnemy->Reset();
        ElimmedEnemy->Destroy();
    }
}
void AShooterLindaGameModeBase::DestroyCharacter(ALindaCharacter* ElimmedCharacter)
{
    if(ElimmedCharacter)
    {
        ElimmedCharacter->Reset();
        ElimmedCharacter->Destroy();
    }
 
}

