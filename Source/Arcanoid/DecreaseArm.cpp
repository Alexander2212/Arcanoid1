// Fill out your copyright notice in the Description page of Project Settings.


#include "DecreaseArm.h"

void ADecreaseArm::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	PowerName = "Capsula de velocidad falsa";
}
void ADecreaseArm::construir()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("se construlle"));

}