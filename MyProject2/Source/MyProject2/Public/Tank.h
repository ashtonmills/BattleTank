// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankAimingComponent;
class UTankBarrel;

class UTankBarrel;
UCLASS()
class MYPROJECT2_API ATank : public APawn
{
	GENERATED_BODY()
public: 
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

private:
	// Sets default values for this pawn's properties
	ATank();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
	
public:	
	virtual void BeginPlay() override;
	// Called every frame

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing) float LaunchSpeed = 100000;//sensible starting value of 1km/s

}
;