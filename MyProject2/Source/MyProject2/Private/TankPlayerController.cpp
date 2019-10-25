// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "AkComponent.h"
#include "Tank.h"


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
		UAkComponent* PlayerAkComponent = nullptr;
		PlayerAkComponent = MyTank->FindComponentByClass<UAkComponent>();
		if (PlayerAkComponent)
		{
			PlayerAkComponent->IsDefaultListener = true;
			if (PlayerAkComponent->IsDefaultListener == true)
			{
				UE_LOG(LogTemp, Warning, TEXT("IsDefaultListener set to true on PlayerAkComponent"));
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("PlayerAkComponent not set to true"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerAkComponent not set"));
		}

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
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) 
{
	//find crosshair position in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//Raycast along that Lookdirecton and see what we hit (up to Max range)
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
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
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * AimRange);
	if (GetWorld()->LineTraceSingleByChannel(Hit, StartLocation,EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation = Hit.Location;
		return true;
	}
		HitLocation = FVector(0);
		return false;
}

