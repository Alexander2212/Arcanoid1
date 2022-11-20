// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Power.h"
#include "PaddlePower.generated.h"

UCLASS()
class ARCANOID_API APaddlePower : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APaddlePower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual APower* ConcoctPower(FString PowerSKU)
		PURE_VIRTUAL(APaddlePower::ConcoctPower, return nullptr;);
	//Order, concoct and returns a Potion of a specific Category
	APower* OrderPower(FString Category);
};
