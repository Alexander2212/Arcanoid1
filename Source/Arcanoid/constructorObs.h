// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.h"
#include "constructorObs.generated.h"

UCLASS()
class ARCANOID_API AconstructorObs : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AconstructorObs();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual AObstaculo* ConcoctObstaculo(FString obsSKU)
		PURE_VIRTUAL(AconstructorObs::ConcoctObstaculo, return nullptr;);
	//Ordena, elabora y devuelve un poder de una categoría específica
	AObstaculo* OrdenObstaculo(FString Category);
};
