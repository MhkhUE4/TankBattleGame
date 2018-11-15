// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h" 
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
protected:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Start the tank moving the barrel so that a shot would hit where
	// the cross hair intersects the world
	void  AimTowardsCrosshair();

	// return OUT parameter , true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnyWhere)
		float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnyWhere)
		float CrossHairYLocation = 0.3333;
	
	UPROPERTY(EditAnyWhere)
		float LineTraceRange = 1000000; // Cm to Kilometers

	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
