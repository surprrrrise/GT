// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridBaseActor.h"

#include "GridManagerActor.generated.h"


/*
	ÿ��grid����Ϣ
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

UCLASS()
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
		}
		return GridManagerActor;
	}

private:
	static AGridManagerActor* GridManagerActor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void BuildLevel(TArray<AActor*>& GridActorArray);
	void BuildLevel(TArray<AGridBaseActor*>& GridActorArray);

	AGridBaseActor* GetRelativeGrid(AGridBaseActor*, int32, TArray<AGridBaseActor*>&);

public:
	void SetCurrentGrid(AGridBaseActor* Value, TArray<AGridBaseActor*>&);

public:
	//	grid���б�
	TArray<AGridBaseActor*> GridList;
	//	grid��ӳ��map
	TMap<AGridBaseActor*, FGridAdjacentInfo> GridMappingMap;

	AGridBaseActor* CurrentGrid;
};
