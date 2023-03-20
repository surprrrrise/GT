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
	//	输入处理
	void UpPress();
	void DownPress();
	void RightPress();
	void LeftPress();

	void Move();

	void MoveToTarget(AGridBaseActor* Target);

public:
	AGridBaseActor* GetCurrentGrid();

public:
	//	人物的mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		TObjectPtr<UStaticMeshComponent> Mesh;

	//	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		float Velocity;

private:
	//	输入类型
	ERoleInput inputType = None;

	//	是否在移动
	bool isMoving = false;

};
