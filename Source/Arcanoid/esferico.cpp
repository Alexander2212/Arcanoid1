// Fill out your copyright notice in the Description page of Project Settings.


#include "esferico.h"

void Aesferico::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreObstaculo = "esfera";
}
void Aesferico::construirobs()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("se construlle"));
}