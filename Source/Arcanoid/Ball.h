// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

class UProjectileMovementComponent;

UCLASS()
class ARCANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
	virtual void Launch();
	bool BallLaunched;

	UFUNCTION()
		UStaticMeshComponent* GetBall();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*UPROPERTY(EditAnywhere)
		class USceneComponent* Scene;*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Ball;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UProjectileMovementComponent* ProjectileMovement;

	//UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	//	class USphereComponent* SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCapsuleComponent* Collision;

	float SpeedModifierOnBounce = 1.02f; //Modificador de velocidad
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DestroyBall();
};
