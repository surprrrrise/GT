// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridBaseActor.generated.h"

USTRUCT(BlueprintType, Category = "TF|Grid|Tower", DisplayName = "Grid Interaction Info")
struct FGridInteractionInfo
{
public:
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
	bool isEnable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
	float Size;
};

USTRUCT(BlueprintType, Category = "TF|Grid|Tower", DisplayName = "Grid Attacking Info")
struct FGridAttackingInfo
{
public:
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
	bool isEnable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
	float Value;
};


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
	//	迷雾的getter/setter
	void SetFogStatus(bool flag);
	bool GetFogStatus()const { return isFogEnable; }

	//	高度的getter/setter
	void SetHeight(const float& val) { HeightInfo = val; }
	float GetHeight() const { return HeightInfo; }

	bool isInteractionEffect() { return isDeform; }

public:
	void Deform();

public:
	void SetAttacking();

public:
	//	地面的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		TObjectPtr<UStaticMeshComponent> GridMesh;

	//	迷雾的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		TObjectPtr<UStaticMeshComponent> FogMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
	FTransform FogRelativeTransform;

	//	网格的编号
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		int32 GridNum;

	//	grid的交互信息
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		FGridInteractionInfo GridInteractionInfo;
	//	grid的攻击信息
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Grid|Tower")
		FGridAttackingInfo GridAttackingInfo;

private:
	bool isFogEnable{ true };

	bool isDeform{ false };

	float HeightInfo{ 1.f };

	float FogDisableTime;

	float CurFogDisableTime;
};
