// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Ball.h"
#include "UObject/ConstructorHelpers.h"

//#include "Components/BoxComponent.h"

//Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BrickMessAsset(TEXT("/Game/Meshes/SM_Brick.SM_Brick"));

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	BoxCollision->SetBoxExtent(FVector(25.5f, 12.0f, 12.0f));

	SM_Brick = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Brick"));
	SM_Brick->SetStaticMesh(BrickMessAsset.Object);
	SM_Brick->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SM_Brick->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BoxCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();

	//BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ABrick::OnOverlapBegin);

}
// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnOverlapBegin(AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Ball")) {
		ABall* MyBall = Cast<ABall>(OtherActor);

		FVector BallVelocity = MyBall->GetVelocity();
		BallVelocity *= (SpeedModifierOnBounce - 1.0f);

		MyBall->GetBall()->SetPhysicsLinearVelocity(BallVelocity, true);

		FTimerHandle UnusedHandle;
		GetWorldTimerManager().SetTimer(UnusedHandle, this, &ABrick::DestroyBrick, 0.1f, false);

		FVector GetLocation = this->GetActorLocation();
	}

}


void ABrick::DestroyBrick()
{
	this->Destroy();
}



