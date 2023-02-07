// Fill out your copyright notice in the Description page of Project Settings.


#include "esferico.h"

void Aesferico::BeginPlay()
{
	Super::BeginPlay();
	//Set the ingredients
	NombreObstaculo = "esfera";

	
}
void Aesferico::construirobs()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("se construlle"));
}

Aesferico::Aesferico()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> esferaMessAsset(TEXT("StaticMesh'/Game/Meshes/SM_Ball.SM_Ball'"));

	SM_esfera = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("esfera"));
	SM_esfera->SetStaticMesh(esferaMessAsset.Object);
	SM_esfera->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SetRootComponent(SM_esfera);


}
