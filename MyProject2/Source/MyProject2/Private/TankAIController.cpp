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
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank %s"), *PlayerTank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AIController could not find player tank"))
	}

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



ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) { return nullptr; }
	return Cast<ATank>(PlayerTank);
	
}