// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

#include "GridBaseActor.h"

#include "GridManagerActor.generated.h"


/*
	每个grid的信息
*/
USTRUCT()
struct FGridAdjacentInfo
{
public:
	GENERATED_USTRUCT_BODY()

public:
	AGridBaseActor* Up = nullptr;
	AGridBaseActor* Up_Right = nullptr;
	AGridBaseActor* Down_Right = nullptr;
	AGridBaseActor* Down = nullptr;
	AGridBaseActor* Down_Left = nullptr;
	AGridBaseActor* Up_Left = nullptr;
};

UCLASS(BlueprintType, Blueprintable)
class PROJECT_API AGridManagerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridManagerActor(const FObjectInitializer& ObjectInitializer);

	static AGridManagerActor* GetInstance()
	{
		if (GridManagerActor == nullptr)
		{
			GridManagerActor = NewObject<AGridManagerActor>(GWorld->GetWorld());

			//	先获取到场景中所有的grid base
			TArray<AActor*> GridActorArray;
			auto World = GridManagerActor->GetWorld();
			UGameplayStatics::GetAllActorsWithTag(World, TEXT("Grid"), GridActorArray);
			//	构建Grid
			GridManagerActor->BuildLevel(GridActorArray);
		}
		return GridManagerActor;
	}

	static AGridManagerActor* Flush()
	{
		GridManagerActor = NewObject<AGridManagerActor>(GWorld->GetWorld());
		//	先获取到场景中所有的grid base
		TArray<AActor*> GridActorArray;
		auto World = GridManagerActor->GetWorld();
		UGameplayStatics::GetAllActorsWithTag(World, TEXT("Grid"), GridActorArray);
		//	构建Grid
		GridManagerActor->BuildLevel(GridActorArray);
		return GridManagerActor;
	}

private:
	static AGridManagerActor* GridManagerActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void BuildLevel(TArray<AActor*>& GridActorArray);
	void BuildLevel(TArray<AGridBaseActor*>& GridActorArray);

	AGridBaseActor* GetRelativeGrid(AGridBaseActor*, int32, TArray<AGridBaseActor*>&);

	void GridInteractionFunc();

public:
	void SetCurrentGrid(AGridBaseActor* Value, TArray<AGridBaseActor*>&, TArray<float>&, TArray<int>&);

	//void SetHintGrid(AGridBaseActor* Target, TArray< AGridBaseActor*> SceneGridList);

	//void EnableRoleAttacking();

	//void SelectGrid();

	//void ClearSelected();

public:
	//	grid的列表
	UPROPERTY(VisibleAnywhere, Category = "TF|Role")
	TArray<AGridBaseActor*> GridList;
	//	grid的映射map
	UPROPERTY(VisibleAnywhere, Category = "TF|Role")
	TMap<AGridBaseActor*, FGridAdjacentInfo> GridMappingMap;

	UPROPERTY(VisibleAnywhere, Category = "TF|Role")
	AGridBaseActor* CurrentGrid;
//private:
//	bool isEnableRoleAttacking = false;
//
//	TArray<AGridBaseActor*> EnableAttackGridList;
//
//	AGridBaseActor* SelectedGrid;
};
