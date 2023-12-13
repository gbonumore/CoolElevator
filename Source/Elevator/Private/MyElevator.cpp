
#include "MyElevator.h"

AMyElevator::AMyElevator()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsMovingUp = true;
}

void AMyElevator::BeginPlay()
{
	Super::BeginPlay();

	InitialPosition = GetActorLocation();
	FinalPosition = InitialPosition + FVector(0, 0, MovementHeight);

	if (ElevatorCurve)
	{
		FOnTimelineFloat ProgressFunction;
		ProgressFunction.BindUFunction(this, FName("HandleElevatorMovement"));
		ElevatorTimeline.AddInterpFloat(ElevatorCurve, ProgressFunction);
		ElevatorTimeline.SetLooping(true);
	}

	SavedTimelinePosition = 0.f;

}

void AMyElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElevatorTimeline.TickTimeline(DeltaTime);
}

void AMyElevator::ActivateElevator()
{
	ElevatorTimeline.SetPlaybackPosition(SavedTimelinePosition, false);
	ElevatorTimeline.SetPlayRate(MovementSpeed);
	ElevatorTimeline.Play();
}

void AMyElevator::DeactivateElevator()
{
	SavedTimelinePosition = ElevatorTimeline.GetPlaybackPosition();
	ElevatorTimeline.Stop();
}

void AMyElevator::HandleElevatorMovement(float Value)
{
	FVector NewPosition = FMath::Lerp(InitialPosition, FinalPosition, Value);
	SetActorLocation(NewPosition);
}
