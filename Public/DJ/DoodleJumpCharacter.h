// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DoodleJumpCharacter.generated.h"

class UCameraComponent;
class UCameraShake;
class UForceFeedbackEffect;

UCLASS()
class ALLFOUR_API ADoodleJumpCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADoodleJumpCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called upon landing when falling
	virtual void Landed(const FHitResult& Hit) override;
	
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit);
	
	// Launches this character. 
	// I chose to avoid APawn::Jump, because I needed something a lot simpler.
	virtual void AddJumpForce();

	// Called for side to side input (From Third Person Template)
	void MoveRight(const float Value);

	// Returns a clamped location, stopping this character from leaving the screen bounds.
	FVector GetClampedLocation() const;

	void ResetScaleWhenJumping();

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DoodleJump|GameDefaults", meta=(BlueprintProtected="true"))
	FVector JumpVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DoodleJump|FX|Landed", meta = ( BlueprintProtected = "true" ))
	USoundBase* LandedSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "DoodleJump|FX|Landed", meta = ( BlueprintProtected = "true" ))
	TSubclassOf<UCameraShake> LandedShake;

	// Returns camera
	inline UCameraComponent* GetCamera() const { return Camera; }

private:

	// The default camera associated with this character
	UPROPERTY(Category = "Camera", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	UCameraComponent* Camera;

	UPROPERTY(Category = "DoodleJump|Landing", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	FVector ScaleMultiplier;

	UPROPERTY(Category = "DoodleJump|Landing", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	FTimerHandle ScaleTimer;

	UPROPERTY(Category = "DoodleJump|Landing", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	float ScaleResetTime;
	
	UPROPERTY(Category = "DoodleJump|Landing", VisibleAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	FVector DefaultScale;

	// The controller vibration played upon landing
	UPROPERTY(Category = "DoodleJump|FX|Landed", EditAnywhere, BlueprintReadOnly, meta = ( AllowPrivateAccess = "true" ))
	UForceFeedbackEffect* LandedFFE;

};
