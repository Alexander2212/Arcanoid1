// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APaddle::APaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_Paddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Paddle"));
	
	RootComponent = SM_Paddle;

	SM_Paddle->SetEnableGravity(true);
	SM_Paddle->SetConstraintMode(EDOFMode::XZPlane);
	SM_Paddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Paddle->SetCollisionProfileName(TEXT("PhisicActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));

	//SINGLETON
	TArray<AActor*> Instances;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),APaddle::StaticClass(), Instances);
	if (Instances.Num() > 2)
	{
		//If exist at least one of them, set the instance with the first found one
		Instance = Cast<APaddle>(Instances[0]);
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,FString::Printf(TEXT("%s already exists"), *Instance->GetName()));
		//Then Destroy this Actor
		Destroy();
	}

}

void APaddle::MoveHorizontal(float _AxisValue)
{
	AddMovementInput(FVector(_AxisValue, 0.0f, 0.0f), 1.0f, false);
}
// metodo salto que puede ser redefinido, permite el movimiento en el eje z para esquivar los obstaculos
void APaddle::Salto(float _AxisValue)
{
	AddMovementInput(FVector(0.0f,0.0f,_AxisValue), 1.0f, false);
}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

