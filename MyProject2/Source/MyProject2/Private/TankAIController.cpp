// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::SetControlledTank()
{
	AITank = GetControlledTank();
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	SetControlledTank();
	if (AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s"), *AITank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not possessing a tank"))
	}

}