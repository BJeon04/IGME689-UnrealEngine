#include "CollectibleItem.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "FirstPersonPlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameModeBase.h"

ACollectibleItem::ACollectibleItem()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	RootComponent = CollisionSphere;
	CollisionSphere->InitSphereRadius(60.f);
	CollisionSphere->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleItem::OnOverlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ACollectibleItem::BeginPlay()
{
	Super::BeginPlay();
}

void ACollectibleItem::OnOverlap(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, 
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
	// Only react to the player
	AFirstPersonPlayerCharacter* Player = Cast<AFirstPersonPlayerCharacter>(OtherActor);
	if (Player)
	{
		// Tell GameMode
		AGameModeBase* GM = UGameplayStatics::GetGameMode(GetWorld());
		if (GM)
		{
			GM->CallFunctionByNameWithArguments(TEXT("OnCollectiblePickedUp"), *GLog, NULL, true);
		}

		Destroy();
	}
}
