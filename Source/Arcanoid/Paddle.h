// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

class UFloatingPawnMovement;

UCLASS()
class ARCANOID_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();
	int vidas;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Paddle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

	virtual void MoveHorizontal(float _AxisValue);

	virtual void Salto(float _AxisValue);

	UPROPERTY()
		APaddle* Instance;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UFUNCTION()
		//virtual void BeginOverlap(AActor* OtherActor) override;

	//float SpeedModifierOnBounce = 1.01f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
