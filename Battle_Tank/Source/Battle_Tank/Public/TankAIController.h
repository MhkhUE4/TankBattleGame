// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// How close the AI tank get
	UPROPERTY(EditAnywhere, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;
};
