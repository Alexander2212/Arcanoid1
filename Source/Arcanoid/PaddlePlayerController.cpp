// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePlayerController.h"

#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "Paddle.h"
#include "Ball.h"
#include "barrera.h"


APaddlePlayerController::APaddlePlayerController()
{
}

void APaddlePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &APaddlePlayerController::MoveHorizontal);
	InputComponent->BindAction("Launch", IE_Pressed, this, &APaddlePlayerController::Launch);

	InputComponent->BindAction("barrera", IE_Pressed, this, &APaddlePlayerController::barrera);
	
}



void APaddlePlayerController::BeginPlay()
{
	Super::BeginPlay();
	TArray<AActor*> CameraActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);
	SpawnNewBall();
	
}

void APaddlePlayerController::MoveHorizontal(float _AxisValue)
{
	auto MyPawn = Cast<APaddle>(GetPawn());

	if (MyPawn) {
		MyPawn->MoveHorizontal(_AxisValue);
	}


}

void APaddlePlayerController::barrera()
{
	const FVector Ubicacion(20.0f, 50.0f, 100.0f);
	const FRotator Rotacion(0.0f, 0.0f, 0.0f);
	//const FVector Escala(3.5f, 0.5f,0.25f);

	UWorld* const World = GetWorld();

	if (World != nullptr) {
		// Spawn o generacion o creacion de actores en tiempo de ejecucion
		bar = World->SpawnActor<Abarrera>(Ubicacion, Rotacion);
		bar->SetHidden(false);	
	}
}

void APaddlePlayerController::Launch()
{
	MyBall->Launch();
}

void APaddlePlayerController::SpawnNewBall()
{
	if (!MyBall) {
		MyBall = nullptr;
	}

	if (BallObj) {
		MyBall = GetWorld()->SpawnActor<ABall>(BallObj, SpawnLocation, SpawnRotator , Spawn);
	}
}

