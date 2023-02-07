// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubico.h"

void ACubico::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreObstaculo = "Cubo";
}
void ACubico::construirobs()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("se construlle"));
}
