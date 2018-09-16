// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

ATankPawn* ATankAIController::GetControlledTank() const
{
	return Cast<ATankPawn>(GetPawn());
}

ATankPawn * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATankPawn>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player:%s"), *PlayerTank->GetName());
	}

}


