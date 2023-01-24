// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyInterface.h"
#include "UObject/Interface.h"
#include "creadorconcreto.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class Ucreadorconcreto : public IMyInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCANOID_API Icreadorconcreto
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	APaddle* getPaddle()
	{
		APaddle* paddle = new APaddle();
		paddle->vidas = 2;
		return paddle;
	}

	ABala* getBala()
	{
		ABala* bala = new ABala();
		return bala;
	}
};
