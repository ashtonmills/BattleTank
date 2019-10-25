// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "AkComponent.h"
#include "E:/Projects/PersonalLearning/BattleTank/MyProject2 4.23/MyProject2_WwiseProject/GeneratedSoundBanks/Wwise_IDs.h"
#include "Runtime/CoreUObject/Public/UObject/Class.h"
#include "Tank.generated.h"

//forward declarations
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

class UTankBarrel;
UCLASS()
class MYPROJECT2_API ATank : public APawn
{
	GENERATED_BODY()
public: 
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Combat)
		void Fire();

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

	UPROPERTY(EditDefaultsOnly, Category = Firing) float LaunchSpeed = 4000;//sensible starting value of 1km/s

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UFUNCTION(BlueprintImplementableEvent, Category = "Ashton")
		void WwisePostEvent();

	void setWwiseComponenet();

private : 
	//lcoal barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;
	double LastFireTime = 0;
	UAkComponent* WwiseComponent = nullptr;
}
;