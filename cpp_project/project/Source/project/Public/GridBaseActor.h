// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridBaseActor.generated.h"

UCLASS()
class PROJECT_API AGridBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void SetFogStatus(bool flag);

public:
	//	迷雾的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		TObjectPtr<UStaticMeshComponent> FogMesh;

	//	地面的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		TObjectPtr<UStaticMeshComponent> GridMesh;

private:
	bool isFogEnable{ true };

	bool isDeform{ false };
};
