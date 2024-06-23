#include "Shooter.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/InputSettings.h"

AShooter::AShooter()
{
    PrimaryActorTick.bCanEverTick = true;

    MuzzleOffset = FVector(100.0f, 0.0f, 50.0f);
}

void AShooter::BeginPlay()
{
    Super::BeginPlay();
    SetupPlayerInputComponent();
}

void AShooter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AShooter::Shoot()
{
    if (ProjectileClass)
    {
        FVector MuzzleLocation = GetActorLocation() + MuzzleOffset;
        FRotator MuzzleRotation = GetActorRotation();

        UWorld* World = GetWorld();
        if (World)
        {
            World->SpawnActor<AProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation);
        }
    }
}

void AShooter::SetupPlayerInputComponent()
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController)
    {
        InputComponent = NewObject<UInputComponent>(this);
        InputComponent->RegisterComponent();
        InputComponent->BindAction("Shoot", IE_Pressed, this, &AShooter::Shoot);
        PlayerController->PushInputComponent(InputComponent);
    }
}
