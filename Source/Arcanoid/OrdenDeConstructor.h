// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "constructorObs.h"
#include "OrdenDeConstructor.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOID_API AOrdenDeConstructor : public AconstructorObs
{
	GENERATED_BODY()
public:
	virtual AObstaculo* ConcoctObstaculo(FString obsSKU) override;
};
