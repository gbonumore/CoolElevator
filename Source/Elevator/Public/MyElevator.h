#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "MyElevator.generated.h"

UCLASS()
class ELEVATOR_API AMyElevator : public AActor
{
	GENERATED_BODY()

public:
	AMyElevator();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Elevator");
	FVector InitialPosition;

	UPROPERTY(VisibleAnywhere, Category = "Elevator");
	FVector FinalPosition;

	UPROPERTY(VisibleAnywhere, Category = "Elevator");
	float SavedTimelinePosition;
	
	UPROPERTY(EditAnywhere, Category = "Elevator")
	float MovementHeight = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Elevator")
	float MovementSpeed = 1.0f;

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	FTimeline ElevatorTimeline;
	
	UPROPERTY(EditAnywhere, Category = "Elevator")
	UCurveFloat* ElevatorCurve;

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	bool bIsMovingUp;

	UFUNCTION()
	void ActivateElevator();

	UFUNCTION()
	void DeactivateElevator();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void HandleElevatorMovement(float Value);
	
};