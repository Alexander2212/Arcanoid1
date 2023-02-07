// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

UCLASS()
class ARCANOID_API AObstaculo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstaculo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

	//nombre del obstaculo
	FString NombreObstaculo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//construye este obstaculo
	virtual void construirobs();
	//devolver el nombre del obstaculo
	FString GetNombreObstaculo();

};
