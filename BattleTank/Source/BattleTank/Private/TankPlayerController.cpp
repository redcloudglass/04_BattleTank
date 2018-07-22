// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

ATankPawn* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController not possessing ATankPawn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController possessing:%s"), *ControlledTank->GetName());
	}

}
