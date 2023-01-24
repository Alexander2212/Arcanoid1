// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"
#include "MyInterface.h"
#include "PaddleAtack.h"
#include "Bala.h"
// Add default functionality here for any IDirector functions that are not pure virtual.

void IDirector::setMyInterface(IMyInterface* newInterface)
{
	builder = newInterface;
}

APaddleAtack* IDirector::getPaddleAtack()
{
	APaddleAtack* paddleatack = new APaddleAtack();

	paddleatack->APaddle = builder->getPaddle();
	paddleatack->ABala = builder->getBala();
	return paddleatack;
}
