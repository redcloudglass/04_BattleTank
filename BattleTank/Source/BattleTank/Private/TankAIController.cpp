// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATankPawn* ATankAIController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possessing ATankPawn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController possessing:%s"), *ControlledTank->GetName());
	}

}


