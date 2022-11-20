// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Power.generated.h"

UCLASS()
class ARCANOID_API APower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APower();

protected:
	//nombre del poder
	FString PowerName;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//construye este poder
	virtual void construir();
	//Return the Potion Name
	FString GetPowerName();
};
