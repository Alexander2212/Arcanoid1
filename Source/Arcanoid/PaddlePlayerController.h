// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;
UCLASS()
class ARCANOID_API APaddlePlayerController : public APlayerController
{

	GENERATED_BODY()

	APaddlePlayerController();

	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;
	void MoveHorizontal(float _AxisValue);
	//incluido ball
	void Launch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(0.0f, 0.0f, 45.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters Spawn;

public:
	void SpawnNewBall();

};
