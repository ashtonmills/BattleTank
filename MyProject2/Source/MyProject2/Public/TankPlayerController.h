// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Runtime/Engine/Public/CollisionQueryParams.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankPlayerController.generated.h"

//forward declaration
class ATank;
/**
 * 
 */
UCLASS()
class MYPROJECT2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* MyTank = nullptr;

	UPROPERTY (EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
		int32 AimRange = 1000000;

public : 
	ATank* GetControlledTank() const;
	void SetControlledTank();
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	//Start the tank moving the barrel so that a shot would hit
	//where the crosshair intersects the world
	void AimAtCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation);
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection);
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation);
};
