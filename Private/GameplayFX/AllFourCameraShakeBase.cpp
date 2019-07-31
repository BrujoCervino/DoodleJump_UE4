// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/GameplayFX/AllFourCameraShakeBase.h"

UAllFourCameraShakeBase::UAllFourCameraShakeBase()
{	
	// Set default ranges:
	PitchAmplitudeMin = 1.25f;
	PitchAmplitudeMax = 2.5f;

	PitchFrequencyMin = 0.1f;
	PitchFrequencyMax = 0.5f;

	ZAmplitudeMin = 5.0f;
	ZAmplitudeMax = 10.0f;

	ZFrequencyMin = 0.1f;
	ZFrequencyMax = 0.5f;

	// Set rotational parameters
	RotOscillation.Pitch.Amplitude = FMath::RandRange(PitchAmplitudeMin, PitchAmplitudeMax);
	RotOscillation.Pitch.Frequency = FMath::RandRange(PitchFrequencyMin, PitchFrequencyMax);

	// Set locational parameters
	LocOscillation.Z.Amplitude = FMath::RandRange(ZAmplitudeMin, ZAmplitudeMax);
	LocOscillation.Z.Frequency = FMath::RandRange(ZFrequencyMin, ZFrequencyMin);

	// Set miscellaneous parameters
	OscillationDuration = 0.25f;
	OscillationBlendOutTime = 0.5f;
}
