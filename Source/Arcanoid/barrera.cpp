// Fill out your copyright notice in the Description page of Project Settings.


#include "barrera.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
Abarrera::Abarrera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("/Game/Meshes/barrera.barrera"));
}

// Called when the game starts or when spawned
void Abarrera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Abarrera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

