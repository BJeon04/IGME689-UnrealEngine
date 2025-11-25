// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectibleItem.generated.h"

UCLASS()
class IGME689_API ACollectibleItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ACollectibleItem();

protected:

	UPROPERTY(VisibleAnywhere, Category="Components")
	class USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category="Components")
	class UStaticMeshComponent* Mesh;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlap(
		UPrimitiveComponent* OverlappedComp, 
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, 
		bool bFromSweep, 
		const FHitResult& SweepResult
	);
};
