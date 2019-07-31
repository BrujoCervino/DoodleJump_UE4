// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Public/DJ/DoodleJumpCharacter.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ADoodleJumpCharacter::ADoodleJumpCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true; // This character can tick
	PrimaryActorTick.bStartWithTickEnabled = true; // Tick starts disabled

	if( GetCapsuleComponent() )
	{
		GetCapsuleComponent()->SetSimulatePhysics(false); // The capsule isn't affected by physics
		GetCapsuleComponent()->SetNotifyRigidBodyCollision(true); // The capsule generates hit events 
	}

	// Create the camera subobject
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	if( GetCamera() )
	{
		GetCamera()->SetupAttachment( GetRootComponent() );
	}

	// Only once, add the player tag to this character
	Tags.AddUnique("Player");

	// Defaults:
	JumpVelocity = FVector(0.0f, 0.0f, 20.0f);
	ScaleMultiplier = FVector(5.0f, 5.0f, 1.0f);
	ScaleResetTime = 0.15f;
	
}

// Called when the game starts or when spawned
void ADoodleJumpCharacter::BeginPlay()
{
	Super::BeginPlay();
	DefaultScale = GetMesh()->GetComponentScale();
}

// Called every frame
void ADoodleJumpCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Clamp this character's location, to avoid leaving the screen bounds.
	SetActorLocation( GetClampedLocation() );

}

// Called to bind functionality to input
void ADoodleJumpCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &ADoodleJumpCharacter::MoveRight);

}

void ADoodleJumpCharacter::Landed(const FHitResult & Hit)
{
	AddJumpForce();
}

void ADoodleJumpCharacter::NotifyHit(UPrimitiveComponent * MyComp, AActor * Other, UPrimitiveComponent * OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult & Hit)
{
	// Jump
	AddJumpForce();

	// Scale the mesh
	FVector const  Scale = GetMesh()->GetComponentScale();
	GetMesh()->SetWorldScale3D(Scale*ScaleMultiplier); 
	// Reset the scale
	GetWorldTimerManager().SetTimer(ScaleTimer, this, &ADoodleJumpCharacter::ResetScaleWhenJumping, ScaleResetTime);

	GetCapsuleComponent()->SetSimulatePhysics(false);

	UGameplayStatics::PlaySound2D(this, LandedSound, FMath::FRandRange(0.75f, 1.25f));

	// Play a screenshake
	APlayerController* const PC = Cast<APlayerController, AController>( GetController() );
	PC->ClientPlayCameraShake(LandedShake);
	PC->ClientPlayForceFeedback(LandedFFE, false,TEXT("Landed"));

}

void ADoodleJumpCharacter::AddJumpForce()
{
	AddActorLocalOffset(JumpVelocity);

	

}

void ADoodleJumpCharacter::MoveRight(const float Value)
{
	if( ( GetController() != NULL ) && ( Value != 0.0f ) )
	{
		// find out which way is right
		const FRotator Rotation = GetController()->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value, true);
		
	}

}

FVector ADoodleJumpCharacter::GetClampedLocation() const
{
	FVector const CurrentLoc = GetActorLocation();
	return
		FVector
		(
			165.0f,
			FMath::Clamp(CurrentLoc.Y, -600.0f, 600.0f),
			CurrentLoc.Z
		);
}

void ADoodleJumpCharacter::ResetScaleWhenJumping()
{
	GetMesh()->SetWorldScale3D(DefaultScale);
}
