// Fill out your copyright notice in the Description page of Project Settings.


#include "DecreaseSize.h"

void ADecreaseSize::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	PowerName = "Capsula de tamaño falsa";
}
void ADecreaseSize::construir()
{
	//Log the brewing type
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("se construlle"));

}