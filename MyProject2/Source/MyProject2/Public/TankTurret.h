// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class MYPROJECT2_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
		float MaxTurnSpeed = 10.0f;
public:
	void Turn(float RelativeSpeed);

};
