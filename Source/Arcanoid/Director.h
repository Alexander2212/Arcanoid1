// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Director.generated.h"
#include "MyInterface.h"
#include "PaddleAtack.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDirector : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCANOID_API IDirector
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
private:
	IMyInterface* builder;
public:
	void setMyInterface(IMyInterface* newInterface);
	APaddleAtack* getPaddleAtack();
};
