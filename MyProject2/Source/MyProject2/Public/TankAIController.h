// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

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
	void LogPossessStatus();
	void BeginPlay() override;
	void SetControlledTank();
	ATank* GetControlledTank() const;

	
};
