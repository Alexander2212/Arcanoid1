// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Power.h"
#include "DecreaseSize.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOID_API ADecreaseSize : public APower
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	//Brew the potion
	virtual void construir() override;
};
