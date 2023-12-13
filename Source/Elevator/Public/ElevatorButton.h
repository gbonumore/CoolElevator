
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyElevator.h"
#include "Components/BoxComponent.h"
#include "ElevatorButton.generated.h"

UCLASS()
class ELEVATOR_API AElevatorButton : public AActor
{
	GENERATED_BODY()

public:    
	AElevatorButton();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Elevator")
	AMyElevator* LinkedElevator;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* InteractionTrigger;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ButtonMesh;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnButtonPressed();

	UFUNCTION()
	void OnButtonReleased();
	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};