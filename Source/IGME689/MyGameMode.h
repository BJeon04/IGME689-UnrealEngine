#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameMode.generated.h"

UCLASS()
class IGME689_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AMyGameMode();

	// How many collectibles exist in the level
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	int32 TotalCollectibles;

	// How many the player has collected
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Gameplay")
	int32 CollectedCount;

	// Called by collectibles when the player picks one up
	UFUNCTION()
	void OnCollectiblePickedUp();

private:
	// Checks if player has collected them all
	void CheckWinCondition();
};
