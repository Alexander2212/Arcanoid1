// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bala.generated.h"

UCLASS()
class ARCANOID_API ABala : public AActor 
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABala();
	UFUNCTION()
		void NotifyActorBeginOverlap(AActor* OtherActor); //Evento de colision
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UStaticMeshComponent* Bala; //Malla del projectil

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UProjectileMovementComponent* Movement; //Movimiento de la bala

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
		class UCapsuleComponent* Collision; //Colision de la bala

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FORCEINLINE UStaticMeshComponent* GetBala() const { return Bala; } //Obtenemos la malla de la bala

	FORCEINLINE UProjectileMovementComponent* GetMovement() const { return Movement; } //Obtenemos el movimiento
};
