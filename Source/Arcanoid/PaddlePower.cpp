// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePower.h"

// Sets default values
APaddlePower::APaddlePower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APaddlePower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddlePower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APower* APaddlePower::OrderPower(FString Category)
{
	//Create the Potion and log its name
	APower* Power = ConcoctPower(Category);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Creando %s"), *Power->GetPowerName()));
	//Start the concoct process
	Power->construir();
	
	return Power;
}

