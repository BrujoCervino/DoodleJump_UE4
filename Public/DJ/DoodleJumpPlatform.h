// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoodleJumpPlatform.generated.h"

UCLASS()
class ALLFOUR_API ADoodleJumpPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoodleJumpPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	// The speed at which this platform oscillates
	UPROPERTY(Category = "DoodleJump|Platform", EditAnywhere, meta = ( BlueprintProtected = "true" ))
	FVector MoveSpeed;

};
