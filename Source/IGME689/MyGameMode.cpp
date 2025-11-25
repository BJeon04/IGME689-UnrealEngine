#include "MyGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

AMyGameMode::AMyGameMode()
{
	TotalCollectibles = 3;   // default requirement
	CollectedCount = 0;
}

void AMyGameMode::OnCollectiblePickedUp()
{
	CollectedCount++;

	UE_LOG(LogTemp, Warning, TEXT("Collected: %d / %d"), CollectedCount, TotalCollectibles);

	CheckWinCondition();
}

void AMyGameMode::CheckWinCondition()
{
	if (CollectedCount >= TotalCollectibles)
	{
		// Print on screen
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(
				-1,            // key (-1 means add new)
				10.0f,         // how long
				FColor::Green, // color
				TEXT("YOU WIN!")
			);
		}

		// Freeze the game
		APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		if (PC)
		{
			PC->SetPause(true);
		}

		UE_LOG(LogTemp, Warning, TEXT("YOU WIN!"));
	}
}
