// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePower_Decrease.h"
#include "DecreaseVelocity.h"
#include "DecreaseSize.h"
#include "DecreaseArm.h"

APower* APaddlePower_Decrease::ConcoctPower(FString PowerSKU)
{
	if (PowerSKU.Equals("Velocidad_Falsa")) {
		return GetWorld()->SpawnActor<ADecreaseVelocity>
			(ADecreaseVelocity::StaticClass());
	}
	else if (PowerSKU.Equals("tamaño_falso")) {
		return GetWorld()->SpawnActor<ADecreaseSize>
			(ADecreaseSize::StaticClass());
	}
	else if (PowerSKU.Equals("Arma_falsa")) {
		return GetWorld()->SpawnActor<ADecreaseArm>
			(ADecreaseArm::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid
}

