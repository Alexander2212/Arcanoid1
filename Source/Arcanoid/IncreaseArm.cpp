// Fill out your copyright notice in the Description page of Project Settings.


#include "IncreaseArm.h"

void AIncreaseArm::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	PowerName = "Capsula de armas";
}
void AIncreaseArm::construir()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("se construlle"));
	
}