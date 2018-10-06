// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "GameFramework/Actor.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// Given max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	float RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationChange;
	UE_LOG(LogTemp, Warning, TEXT("TankTurret Rotate: %f"), Rotation);

	SetRelativeRotation(FRotator(0, Rotation, 0));
}


