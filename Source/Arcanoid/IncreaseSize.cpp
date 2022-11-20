// Fill out your copyright notice in the Description page of Project Settings.


#include "IncreaseSize.h"

void AIncreaseSize::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	PowerName = "Capsula de tamaño";
}
void AIncreaseSize::construir()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("se construlle"));
}