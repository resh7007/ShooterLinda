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
