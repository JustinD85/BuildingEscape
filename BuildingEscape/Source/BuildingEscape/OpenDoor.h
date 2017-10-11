// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenDoor()
	{
		GetOwner()->SetActorRotation(FRotator(0.f, doorOpenAcute, 0.f));
	}

	void CloseDoor()
	{
		GetOwner()->SetActorRotation(FRotator(0.f, -89.999939f, 0.f));
	}
private:

	UPROPERTY(EditAnywhere)
		float doorOpenAcute = -45.f;

	UPROPERTY(EditAnywhere)
		AActor* PlayerPawn;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;

	float DoorLastOpenTime;

	UPROPERTY(EditAnywhere)
		float DoorDelay = 1.f;
	
};
