// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankAIController.generated.h"

//forward declaration
class ATank;

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ATankAIController : public AAIController
{
	GENERATED_BODY()
private :
	ATank* AITank=nullptr;
public :
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
};
