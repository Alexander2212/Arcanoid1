// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PaddlePlayerController.generated.h"

/**
 * 
 */
class ABall;
class Abarrera;
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

	void Salto(float _AxisValue);
	//incluido ball
	void Launch();

	void barrera();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;
	FVector SpawnLocation = FVector(20.0f, 0.0f, 45.0f);
	FRotator SpawnRotator = FRotator(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters Spawn;

	Abarrera* bar;

public:
	void SpawnNewBall();

};
