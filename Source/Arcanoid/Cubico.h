// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "Cubico.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOID_API ACubico : public AObstaculo
{
	GENERATED_BODY()

protected:
	//Llamado cuando comienza el juego o cuando se genera
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;
public:
	//Prepara el obstaculo
	virtual void construirobs() override;
	ACubico();
	
};
