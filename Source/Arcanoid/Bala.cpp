// Fill out your copyright notice in the Description page of Project Settings.


#include "Bala.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Brick.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABala::ABala()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BalaMesh(TEXT("StaticMesh'/Game/Meshes/SM_Ball.SM_Ball'"));


	Bala = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Bala->SetStaticMesh(BalaMesh.Object);
	SetRootComponent(Bala);

	Collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision"));
	Collision->SetCapsuleHalfHeight(15.0f);
	Collision->SetCapsuleRadius(10.0f);
	Collision->SetupAttachment(GetRootComponent());

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Bala;
	Movement->InitialSpeed = 500.f;
	Movement->MaxSpeed = 500.f;
	Movement->bRotationFollowsVelocity = true;
	Movement->bShouldBounce = false;
	Movement->ProjectileGravityScale = 0.0f;

	InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void ABala::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABala::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ABrick* Brick = Cast<ABrick>(OtherActor);
	if (Brick) {
		this->Destroy();
		Brick->DestroyBrick();
	}
}
// Called every frame
void ABala::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetActorLocation().Z >= 450.0f) {this->Destroy();
	}
}

