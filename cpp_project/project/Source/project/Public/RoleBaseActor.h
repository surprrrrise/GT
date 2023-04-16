// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridBaseActor.h"
#include "GridSelectedActor.h"

#include "RoleBaseActor.generated.h"

UCLASS()
class PROJECT_API ARoleBaseActor : public APawn
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

	struct FAttackingInfo
	{
		TArray<float> AttackingValue{};
		TArray<int> AttackingDuration{};
	};

public:	
	// Sets default values for this actor's properties
	ARoleBaseActor();

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void Dead();

	void Win();

	void OpenFog();

	void Attack();

	void AttackedByEnemy(float Value);

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

	//	获取到终点grid
	TArray<AGridBaseActor*> GetTerminalGrid(TArray<AActor*>&);

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

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role|UI")
	TSubclassOf<UUserWidget> WinWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role|UI")
	TSubclassOf<UUserWidget> LoseWidget;

public:
	//	输入类型
	ERoleInput inputType = None;

	//	是否在移动
	bool isMoving = false;

	bool isDead = false;

	//	人物当前的San值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	float CurrentSanValue;

	FVector TargetLocation;
	FVector MoveDirection;

	UPROPERTY(VisibleAnywhere, Category = "TF|Role")
	AGridBaseActor* CurrentGrid;

	float SanDeltaValue;

	float CrossGridMaxGeight;

	UPROPERTY(VisibleAnywhere, Category = "TF|Role")
	TArray<AGridBaseActor*> SceneGridList;

private:
	FAttackingInfo AttackingInfo;

	AGridSelectedActor* GridSelectedActor;

	TArray<AGridBaseActor*> TerminalGrid;
};
