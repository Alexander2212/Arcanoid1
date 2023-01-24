// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"


class UBoxComponent;
UCLASS()
class ARCANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Collision;

	float SpeedModifierOnBounce = 1.01f;

	UFUNCTION()
			virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;


	//void OnOverlapBegin(class AActor* OtherActor);

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void DestroyBrick();
};
