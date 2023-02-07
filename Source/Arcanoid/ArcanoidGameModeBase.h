// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ArcanoidGameModeBase.generated.h"

/**
 * 
 */

class ABrick;
class ACubico;
UCLASS()
class ARCANOID_API AArcanoidGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	

	ABrick* ladrillo01;

	//Singleton


	AArcanoidGameModeBase();

protected:
	virtual void BeginPlay() override;

	TArray<ABrick*> LineBricks;

	UPROPERTY()
		class ABrick* Brick;
private:
	UPROPERTY()
		class APaddle* Paddle;
public:
	virtual void Tick(float DeltaTime) override;

};
