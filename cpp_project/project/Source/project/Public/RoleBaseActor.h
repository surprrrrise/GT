// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridBaseActor.h"

#include "RoleBaseActor.generated.h"

UCLASS()
class PROJECT_API ARoleBaseActor : public AActor
{
	GENERATED_BODY()
	
public:
	enum ERoleInput
	{
		Right,
		Left,

		Up,
		Right_Up,
		Right_Down,
		Down,
		Left_Down,
		Left_Up,

		None
	};

public:	
	// Sets default values for this actor's properties
	ARoleBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Dead();

	void OpenFog();

public:
	//	输入处理
	void UpPress();
	void DownPress();
	void RightPress();
	void LeftPress();

	void Move();

public:
	//	获取到人物当前所在的网格
	AGridBaseActor* GetCurrentGrid(TArray<AGridBaseActor*>& GridList);

	//	获取到场景中的Grid
	TArray<AGridBaseActor*> GetGridList();

public:
	//	人物的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	TObjectPtr<UStaticMeshComponent> Mesh;

	//	人物移动的速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	float Velocity;

	//	人物的san值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	float SanValue;

private:
	//	输入类型
	ERoleInput inputType = None;

	//	是否在移动
	bool isMoving = false;

	//	人物当前的San值
	float CurrentSanValue;

	FVector TargetLocation;
	FVector MoveDirection;

	AGridBaseActor* CurrentGrid;

	float SanDeltaValue;

	float CrossGridMaxGeight;

	TArray<AGridBaseActor*> SceneGridList;
};
