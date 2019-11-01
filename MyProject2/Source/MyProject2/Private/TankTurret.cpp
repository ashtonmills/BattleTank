// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Turn(float RelativeSpeed)
{
//if (GetOwner()->isPlayerPawn)
	//{

	//}
	//UE_LOG(LogTemp, Warning, TEXT("should be turning turret"));
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto TurnChange = RelativeSpeed * MaxTurnSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewTurn = RelativeRotation.Yaw + TurnChange;
	SetRelativeRotation(FRotator(0, NewTurn, 0));
}