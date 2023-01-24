// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaddleAtack.generated.h"
#include "Paddle.h"
#include "Bala.h"


UCLASS()
class ARCANOID_API APaddleAtack : public AActor
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	APaddleAtack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void specifications()
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("vidas:"), Paddle->vidas));
		
	}

	APaddle* Paddle;
	ABala* Bala;

};
