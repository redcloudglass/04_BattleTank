// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPawn.h"
#include "GameFramework/Actor.h"
#include "TankAimingComponent.h"


// Sets default values
ATankPawn::ATankPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointers as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATankPawn::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATankPawn::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fired."), Time);
}

void ATankPawn::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	//Barrel = BarrelToSet;
}

void ATankPawn::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Called when the game starts or when spawned
void ATankPawn::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATankPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

