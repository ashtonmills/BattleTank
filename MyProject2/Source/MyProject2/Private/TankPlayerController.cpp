// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::SetControlledTank()
{
	MyTank = GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetControlledTank();
	if (MyTank)
	{
		UE_LOG(LogTemp,Warning,TEXT("PlayerController possessing %s"), *MyTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController not possessing a tank"))
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();

}

void ATankPlayerController::AimAtCrosshair()
{
	if (!MyTank) { return; }
	FVector HitLocation; //out parameter
	GetSightRayHitLocation(HitLocation);
	//Get world location if raycast through crosshair
	//if it hits landscape
	  //tell controlled tank to aim at theis point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) 
{
	//find crosshair position in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Raycast along that Lookdirecton and see what we hit (up to Max range)
		FVector HitLocation;
		GetLookVectorHitLocation(LookDirection,HitLocation);
		UE_LOG(LogTemp, Warning, TEXT("HitDirection: %s "), *HitLocation.ToString());
	}
	HitLocation = FVector(0);
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) 
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)
{
	//make the raycast by single channnl
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * AimRange);
	if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation,EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;
		return true;
	}
	else return false;
}
