// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharactor.generated.h"

UCLASS()
class PROJECT_API AEnemyCharactor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharactor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Dead();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Enemy")
		int32 HeartValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Enemy")
		int32 HP;
};
