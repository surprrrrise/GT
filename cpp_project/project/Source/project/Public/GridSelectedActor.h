// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridSelectedActor.generated.h"

class AGridBaseActor;

UCLASS()
class PROJECT_API AGridSelectedActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridSelectedActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void ClearSelected();
	void SetHintGrid(AGridBaseActor* Target, TArray< AGridBaseActor*> SceneGridList);
	void EnableRoleAttacking();
	void SelectGrid();

private:
	bool isEnableInput = false;
	bool isEnableRoleAttacking = false;

	TArray<AGridBaseActor*> EnableAttackGridList;

	AGridBaseActor* SelectedGrid;
};
