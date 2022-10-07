// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ShooterLindaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERLINDA_API AShooterLindaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	virtual void PlayerEliminated(class ALindaCharacter* ElimmedCharacter, class ALindaPlayerController* VictimController);
	virtual void EnemyEliminated(class AEnemies* ElimmedEnemy);

};
