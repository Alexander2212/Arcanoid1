// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArcanoidGameModeBase.h"
#include "Brick.h"
#include "Paddle.h"
#include "PaddlePower_Increase.h"

AArcanoidGameModeBase::AArcanoidGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
}
void AArcanoidGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//singleton-*
	// Set this actor to call Tick() every frame. You can turn this off to
	//improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
	//singleton*-

	const FVector Ubicacion(20.0f, 50.0f, 100.0f);
	const FRotator Rotacion(0.0f, 0.0f, 0.0f);

	UWorld* const World = GetWorld();

	if (World != nullptr) {
		// Spawn o generacion o creacion de actores en tiempo de ejecucion
		ladrillo01 = World->SpawnActor<ABrick>(Ubicacion, Rotacion);
		ladrillo01->SetHidden(false);
		GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("Actor ladrillo 01 creado"));

	}

	//singleton-*
	for (int i = 0; i <= 1; i++)
	{
		APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass());
		if (SpawnedPaddle)
		{
			//If the Spawn succeeds, set the Spawned inventory to the local one
			//and log the success string
				Paddle = SpawnedPaddle;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s has been created"), *Paddle->GetName()));
		}
	}
	//singleton*-

	//factory metod-*

	//Create the Shops
	APaddlePower* PaddlePower_Increase = GetWorld() -> SpawnActor<APaddlePower_Increase>(APaddlePower_Increase::StaticClass());
	//APotionShop* InnerRealmShop = GetWorld() -> SpawnActor<AInnerRealmPotionShop>(AInnerRealmPotionShop::StaticClass());
	//Create an Outer Health Potion and log its name
	APower* Power = PaddlePower_Increase->OrderPower("Velocidad");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Power is %s"), *Power->GetPowerName()));
	//Create an Inner Health Potion and log its name
	Power = PaddlePower_Increase->OrderPower("tamaño");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Potion is %s"), *Power->GetPowerName()));
	//Create an Outer Power Potion and log its name
	Power = PaddlePower_Increase->OrderPower("Arma");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Potion is %s"), *Power->GetPowerName()));
	////Create an Inner Health Potion and log its name
	//Potion = InnerRealmShop->OrderPotion("Power");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
	////Create an Outer Skill Potion and log its name
	//Potion = OuterRealmShop->OrderPotion("Skill");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
	////Create an Inner Health Potion and log its name
	//Potion = InnerRealmShop->OrderPotion("Skill");
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("Potion is %s"), *Potion->GetPotionName()));
}
void AArcanoidGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

