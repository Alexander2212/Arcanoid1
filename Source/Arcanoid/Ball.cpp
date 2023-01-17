// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"


void ABall::Launch()
{
	if (!BallLaunched) {
		SM_Ball->AddImpulse(FVector(140.0f, 0.0f, 130.0f), FName(), true);
		BallLaunched = true;
	}

}

UStaticMeshComponent* ABall::GetBall()
{
	return SM_Ball;
}


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));

	SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	SphereCollision->SetConstraintMode(EDOFMode::XZPlane);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));

	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 1.1f;
	ProjectileMovement->Friction = 0.0f;
	ProjectileMovement->Velocity.X = 0.0f;


	SM_Ball->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SphereCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

