// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces to the tank for movement
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class MYPROJECT2_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void setThrottle(float Throttle);
	
	//Maxforce pre track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Movement)
		float TrackMaxDrivingForce;
};
