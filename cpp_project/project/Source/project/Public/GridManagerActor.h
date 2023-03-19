// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "LevelDesignAsset.h"

#include "GridManagerActor.generated.h"




UCLASS()
class PROJECT_API AGridManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManagerActor();

	static AGridManagerActor* GetInstance()
	{
		if (GridManagerActor == nullptr)
		{
			GridManagerActor = NewObject<AGridManagerActor>();
		}
		return GridManagerActor;
	}


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|GridManager")
	TObjectPtr<ULevelDesignAsset> LevelDesignAsset;



public:
	void BuildLevel();
private:
	static AGridManagerActor* GridManagerActor;
};
