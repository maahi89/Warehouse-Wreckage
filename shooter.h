#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shooter.generated.h"

UCLASS()
class YOURPROJECT_API AShooter : public AActor
{
    GENERATED_BODY()
    
public:    
    AShooter();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    void Shoot();

    UPROPERTY(EditDefaultsOnly, Category = "Shooting")
    TSubclassOf<class AProjectile> ProjectileClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
    FVector MuzzleOffset;

private:
    void SetupPlayerInputComponent();
};
