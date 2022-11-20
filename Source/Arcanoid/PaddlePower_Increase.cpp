// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePower_Increase.h"
#include "IncreaseVelocity.h"
#include "IncreaseSize.h"
#include "IncreaseArm.h"

APower* APaddlePower_Increase::ConcoctPower(FString PowerSKU)
{
	if (PowerSKU.Equals("Velocidad")) {
		return GetWorld()->SpawnActor<AIncreaseVelocity>
			(AIncreaseVelocity::StaticClass());
	}
	else if (PowerSKU.Equals("tamaño")) {
		return GetWorld()->SpawnActor<AIncreaseSize>
			(AIncreaseSize::StaticClass());
	}
	else if (PowerSKU.Equals("Arma")) {
		return GetWorld()->SpawnActor<AIncreaseArm>
			(AIncreaseArm::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid
}
	
