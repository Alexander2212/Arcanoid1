// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyInterface.generated.h"
#include "Bala.h"
#include "Paddle.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCANOID_API IMyInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual APaddle* getPaddle() = 0;
	virtual ABala* getBala() = 0;

	//virtual void ConsPaddle() = 0;
	//virtual void ConsBala() = 0;
	
};
