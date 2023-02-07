// Fill out your copyright notice in the Description page of Project Settings.


#include "constructorObs.h"

// Sets default values
AconstructorObs::AconstructorObs()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AconstructorObs::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AconstructorObs::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
AObstaculo* AconstructorObs::OrdenObstaculo(FString Category)
{
	//Create the Potion and log its name
	AObstaculo* Obstaculo = ConcoctObstaculo(Category);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("Creando %s"), *Obstaculo->GetNombreObstaculo()));
	//Start the concoct process
	Obstaculo->construirobs();

	return Obstaculo;
}

