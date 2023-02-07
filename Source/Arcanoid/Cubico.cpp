// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubico.h"
#include "UObject/ConstructorHelpers.h"

void ACubico::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreObstaculo = "Cubo";
}
void ACubico::construirobs()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("se esta construllendo"));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'"));

	//SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	//SM_Brick->SetStaticMesh(BrickMessAsset.Object);
	//SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	//SetRootComponent(SM_Brick);
	//PrimaryActorTick.bCanEverTick = true;
}

ACubico::ACubico()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("StaticMesh'/Game/Meshes/SM_Brick.SM_Brick'"));

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cubo"));
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetRootComponent(SM_Brick);
}
