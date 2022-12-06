// Fill out your copyright notice in the Description page of Project Settings.


#include "DecreaseVelocity.h"

void ADecreaseVelocity::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	PowerName = "Capsula de velocidad falsa";
}
void ADecreaseVelocity::construir()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("se construlle"));

}