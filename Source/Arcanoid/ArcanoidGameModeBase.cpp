// Copyright Epic Games, Inc. All Rights Reserved.


#include "ArcanoidGameModeBase.h"
#include "Brick.h"
#include "Paddle.h"
#include "PaddlePower_Increase.h"
#include "PaddlePower_Decrease.h"
#include "PaddleAtack.h"
#include "Director.h"
#include "creadorconcreto.h"



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

	 /*const FVector Ubicacion(-150.0f, 50.0f, 200.0f);
	 const FRotator Rotacion(0.0f, 0.0f, 0.0f);*/
	FVector Sl1(-150.0f, 0.0f, 200.0f);
	FVector SL2(50.0f, 0.0f, 0.0f);

	 for (int i = 1; i <= 4; i++) {
		 Brick = GetWorld()->SpawnActor<ABrick>(ABrick::StaticClass(), Sl1, FRotator::ZeroRotator);

		 Sl1 = Sl1 + SL2;
	 }

	//UWorld* const World = GetWorld();

	//if (World != nullptr) {
	//	// Spawn o generacion o creacion de actores en tiempo de ejecucion
	//	ladrillo01 = World->SpawnActor<ABrick>(Ubicacion, Rotacion);
	//	ladrillo01->SetHidden(false);
	//	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Cyan, TEXT("Actor ladrillo 01 creado"));

	//}

	//singleton-*
	for (int i = 0; i <= 1; i++)
	{
		APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass());
		if (SpawnedPaddle)
		{
			//If the Spawn succeeds, set the Spawned inventory to the local one
			//and log the success string
				Paddle = SpawnedPaddle;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s ha sido creado"), *Paddle->GetName()));
		}
	}
	//singleton*-

	//factory metod-*

	//Create the Shops
	APaddlePower* PaddlePower_Increase = GetWorld() -> SpawnActor<APaddlePower_Increase>(APaddlePower_Increase::StaticClass());
	APaddlePower* PaddlePower_Decrease = GetWorld() -> SpawnActor<APaddlePower_Decrease>(APaddlePower_Decrease::StaticClass());
	//Create an Outer Health Potion and log its name
	APower* Power = PaddlePower_Increase->OrderPower("Velocidad");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("El poder es %s"), *Power->GetPowerName()));
	//Create an Inner Health Potion and log its name
	Power = PaddlePower_Increase->OrderPower("tamaño");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("la capsula es %s"), *Power->GetPowerName()));
	//Create an Outer Power Potion and log its name
	Power = PaddlePower_Increase->OrderPower("Arma");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("la capsula es %s"), *Power->GetPowerName()));
	////Create an Inner Health Potion and log its name
	Power = PaddlePower_Decrease->OrderPower("Velocidad_Falsa");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("la capsula es %s"), *Power->GetPowerName()));
	////Create an Outer Skill Potion and log its name
	Power =	PaddlePower_Decrease->OrderPower("tamaño_falso");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("la capsula es %s"), *Power->GetPowerName()));
	////Create an Inner Health Potion and log its name
	Power = PaddlePower_Decrease->OrderPower("Arma_falsa");
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("la capsula es %s"), *Power->GetPowerName()));
	//-------------------------------------------------------Builder-------------------------------------------------------------------------------//

	APaddleAtack* PaddleAtack; // producto final

	/* Un director que controla el proceso */
	IDirector director;

	/* creador concreto */
	Icreadorconcreto CreadorConcreto;

	/* construir paddle */
	
	director.setMyInterface(&CreadorConcreto); // usar lainstancia de MyInterface
	PaddleAtack = director.getPaddleAtack();
	PaddleAtack->specifications();
	//----------------------------------------------------------------------------------------------------------------------------------------------//
}
void AArcanoidGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

