// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaddlePower.h"
#include "PaddlePower_Increase.generated.h"

/**
 * 
 */
UCLASS()
class ARCANOID_API APaddlePower_Increase : public APaddlePower
{
	GENERATED_BODY()

public:
	virtual APower* ConcoctPower(FString PowerSKU) override;
};
