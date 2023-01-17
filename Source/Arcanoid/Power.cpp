// Fill out your copyright notice in the Description page of Project Settings.


#include "Power.h"

// Sets default values
APower::APower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void APower::construir()
{
	//Log the Boil procedure
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("se construye"));

}
FString APower::GetPowerName()
{
	//Return the name of this Potion
	return PowerName;
}
