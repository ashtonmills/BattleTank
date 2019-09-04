// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* MyTank = nullptr;

public : 
	ATank* GetControlledTank() const;
	void SetControlledTank();
	void BeginPlay() override;
};
