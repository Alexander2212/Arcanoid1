// Fill out your copyright notice in the Description page of Project Settings.


#include "OrdenDeConstructor.h"
#include "Cubico.h"
#include "esferico.h"

AObstaculo* AOrdenDeConstructor::ConcoctObstaculo(FString obsSKU)
{
	if (obsSKU.Equals("Cubo")) {
		return GetWorld()->SpawnActor<ACubico>
			(ACubico::StaticClass());
	}
	else if (obsSKU.Equals("esfera")) {
		return GetWorld()->SpawnActor<Aesferico>
			(Aesferico::StaticClass());
	}
	else return nullptr; //Return null if the string isn't valid
}
