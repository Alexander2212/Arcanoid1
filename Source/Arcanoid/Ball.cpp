// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"


void ABall::Launch()
{
	if (!BallLaunched) {
		SM_Ball->AddImpulse(FVector(160.0f, 0.0f, 200.0f), FName(), true);
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
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("StaticMesh'/Game/Meshes/SM_Ball.SM_Ball'"));
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	SM_Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	SM_Ball->SetSimulatePhysics(true);
	SM_Ball->SetEnableGravity(false);
	SM_Ball->SetConstraintMode(EDOFMode::XZPlane);
	SM_Ball->SetStaticMesh(BallMesh.Object);
	SM_Ball->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SM_Ball->SetCollisionProfileName(TEXT("PhysicsActor"));
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	SetRootComponent(SM_Ball);

	//SphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	//SphereCollision->SetConstraintMode(EDOFMode::XZPlane);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 0.0f;
	ProjectileMovement->MaxSpeed = 0.0f;
	ProjectileMovement->bShouldBounce = true; //Debe rebotar
	ProjectileMovement->Bounciness = 1.1f; //Rebote
	ProjectileMovement->Friction = 0.0f; //Friccion
	//ProjectileMovement->bShouldBounce = true;
	//ProjectileMovement->Bounciness = 1.1f;
	//ProjectileMovement->Friction = 0.0f;
	//ProjectileMovement->Velocity.X = 0.0f;


	//SM_Ball->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//SphereCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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

void ABall::DestroyBall()
{
	Destroy();
}

