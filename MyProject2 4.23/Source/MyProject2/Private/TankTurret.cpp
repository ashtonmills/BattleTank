// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Turn(float RelativeSpeed)
{
	

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurnChange = RelativeSpeed * MaxTurnSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewTurn = RelativeRotation.Yaw + TurnChange;
	//lastRotation = NewTurn;
	SetRelativeRotation(FRotator(0, NewTurn, 0));
	UE_LOG(LogTemp, Warning, TEXT("lastRotation: %f"),NewTurn);

}