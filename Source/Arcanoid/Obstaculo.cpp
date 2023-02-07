// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "Cubico.h"
#include "esferico.h"


// Sets default values
AObstaculo::AObstaculo()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementRadius = 5;
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstaculo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AActor* Parent = GetOwner();
	if (Parent)
	{
		// Find a new position for the object to go to
		auto NewPos = Parent->GetActorLocation() + FVector
			(
				FMath::FRandRange(2.5, -1) * MovementRadius,
				FMath::FRandRange(4, 0) * MovementRadius,
				FMath::FRandRange(1, 0) * MovementRadius
			);
		// Update the object's position
		Parent->SetActorLocation(NewPos);
	}
}

void AObstaculo::construirobs()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("se construye"));
}

FString AObstaculo::GetNombreObstaculo()
{
	//Devuelve el nombre de este obstaculo.
	return NombreObstaculo;
}

