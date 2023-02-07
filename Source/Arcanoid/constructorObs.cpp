// Fill out your copyright notice in the Description page of Project Settings.


#include "constructorObs.h"
#include "Cubico.h"
#include "esferico.h"

// Sets default values
AconstructorObs::AconstructorObs()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AconstructorObs::BeginPlay()
{
	//const FVector Ubicacion1(0.0f, 10.0f, 200.0f);
	//const FVector Ubicacion2(10.0f, 10.0f, 200.0f);
	//const FRotator Rotacion(0.0f, 0.0f, 0.0f);

	//UWorld* const World = GetWorld();

	//if (World != nullptr) {
	//	//	// Spawn o generacion o creacion de actores en tiempo de ejecucion
	//	cubo = World->SpawnActor<ACubico>(Ubicacion1, Rotacion);
	//	cubo->SetHidden(false);
	//}
	//if (World != nullptr) {
	//	//	// Spawn o generacion o creacion de actores en tiempo de ejecucion
	//	esfera = World->SpawnActor<Aesferico>(Ubicacion2, Rotacion);
	//	esfera->SetHidden(false);
	//}
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

