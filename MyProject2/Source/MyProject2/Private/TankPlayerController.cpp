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