// ElevatorButton.cpp

#include "ElevatorButton.h"
#include "MyElevator.h"
#include "Components/BoxComponent.h"
#include "Elevator/ElevatorCharacter.h"

AElevatorButton::AElevatorButton()
{
	PrimaryActorTick.bCanEverTick = false;
	InteractionTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractionTrigger"));
	InteractionTrigger->SetupAttachment(RootComponent);
	InteractionTrigger->SetCollisionProfileName(TEXT("Trigger"));

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));
	ButtonMesh->SetupAttachment(InteractionTrigger);

	InteractionTrigger->OnComponentBeginOverlap.AddDynamic(this, &AElevatorButton::OnBeginOverlap);
	InteractionTrigger->OnComponentEndOverlap.AddDynamic(this, &AElevatorButton::OnEndOverlap);
}

void AElevatorButton::BeginPlay()
{
	Super::BeginPlay();

}

void AElevatorButton::OnButtonPressed()
{
	if (LinkedElevator)
	{
		LinkedElevator->ActivateElevator();
	}
}

void AElevatorButton::OnButtonReleased()
{
	if (LinkedElevator)
	{
		LinkedElevator->DeactivateElevator();
	}
}

void AElevatorButton::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool
                                     bFromSweep, const FHitResult& SweepResult)
{
	AElevatorCharacter* PlayerCharacter = Cast<AElevatorCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		OnButtonPressed();
	}
}

void AElevatorButton::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AElevatorCharacter* PlayerCharacter = Cast<AElevatorCharacter>(OtherActor);
	if (PlayerCharacter)
	{
		OnButtonReleased();
	}
}
