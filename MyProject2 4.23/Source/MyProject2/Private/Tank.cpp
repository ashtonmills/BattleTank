// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.GetComponentByClass
	PrimaryActorTick.bCanEverTick = true;

	//thsi is how we can creat custom components for our actors, using c++, rather than adding them in BP
	//no need to protect pointer as added in construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component")); //now this show in the Tank Bluepint as an inherited component that can't be changed or removed.

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

	//this->WwisePostEvent();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::setWwiseComponenet()
{
	WwiseComponent = GetOwner()->FindComponentByClass<UAkComponent>();
}


void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation,LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	if (!ProjectileBlueprint) { UE_LOG(LogTemp,Warning,TEXT("ProjectileBlueprint not assigned to tank")); return; }
	bool bisReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	WwiseComponent->PostAkEventByName("TANK_FIRE");

	if (Barrel && bisReloaded)
	{
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile"))
			);
		Projectile->LauchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}

}