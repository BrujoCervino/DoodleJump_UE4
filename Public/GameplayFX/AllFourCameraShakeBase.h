// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShake.h"
#include "AllFourCameraShakeBase.generated.h"

// The base class for this game's camera shakes.
// Best used Blueprinted.
UCLASS()
class ALLFOUR_API UAllFourCameraShakeBase : public UCameraShake
{
	GENERATED_BODY()

public:

	// Default constructor
	UAllFourCameraShakeBase();

private:

	// Minimal rotation
	UPROPERTY(Category = "AllFourCameraShake|Rotation", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float PitchAmplitudeMin;

	// Maximal rotation
	UPROPERTY(Category = "AllFourCameraShake|Rotation", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float PitchAmplitudeMax;

	// Minimal time to rotate
	UPROPERTY(Category = "AllFourCameraShake|Rotation", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float PitchFrequencyMin;

	// Maximal time to rotate
	UPROPERTY(Category = "AllFourCameraShake|Rotation", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float PitchFrequencyMax;

	// Minimal location
	UPROPERTY(Category = "AllFourCameraShake|Location", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float ZAmplitudeMin;

	// Maximal location
	UPROPERTY(Category = "AllFourCameraShake|Location", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float ZAmplitudeMax;

	// Minimal time to translate
	UPROPERTY(Category = "AllFourCameraShake|Location", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float ZFrequencyMin;

	// Maximal time to translate
	UPROPERTY(Category = "AllFourCameraShake|Location", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "True"))
	float ZFrequencyMax;
};
