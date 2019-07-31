// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/DJ/DoodleJumpPlatform.h"


// Sets default values
ADoodleJumpPlatform::ADoodleJumpPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// General defaults
	MoveSpeed = FVector(0.f, 20.f, 0.f);
}

// Called when the game starts or when spawned
void ADoodleJumpPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoodleJumpPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Oscillate the actor from left to right
	AddActorLocalOffset
	(
		MoveSpeed*FMath::Sin(GetWorld()->TimeSeconds)
	);

}



