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

	UFUNCTION(BlueprintCallable, Category = "Elevator")
	void ActivateElevator();

	UFUNCTION(BlueprintCallable, Category = "Elevator")
	void DeactivateElevator();

	UPROPERTY(EditAnywhere, Category = "Elevator")
	float MovementHeight = 400.0f;

	UPROPERTY(EditAnywhere, Category = "Elevator")
	float MovementSpeed = 1.0f;

protected:
	virtual void BeginPlay() override;

private:
	FTimeline ElevatorTimeline;
	UPROPERTY(EditAnywhere, Category = "Elevator")
	UCurveFloat* ElevatorCurve

	;
	

	UPROPERTY(VisibleAnywhere, Category = "Elevator")
	bool bIsMovingUp;

	UFUNCTION()
	void HandleElevatorMovement(float Value);

	FVector InitialPosition;
	FVector FinalPosition;
	float SavedTimelinePosition;
};