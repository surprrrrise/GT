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
	//	���봦��
	void UpPress();
	void DownPress();
	void RightPress();
	void LeftPress();

	void Move();

public:
	//	��ȡ�����ﵱǰ���ڵ�����
	AGridBaseActor* GetCurrentGrid(TArray<AGridBaseActor*>& GridList);

	//	��ȡ�������е�Grid
	TArray<AGridBaseActor*> GetGridList();

public:
	//	�����mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	TObjectPtr<UStaticMeshComponent> Mesh;

	//	�����ƶ����ٶ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	float Velocity;

	//	�����sanֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
	float SanValue;

private:
	//	��������
	ERoleInput inputType = None;

	//	�Ƿ����ƶ�
	bool isMoving = false;

	//	���ﵱǰ��Sanֵ
	float CurrentSanValue;

	FVector TargetLocation;
	FVector MoveDirection;

	AGridBaseActor* CurrentGrid;

	float SanDeltaValue;

	float CrossGridMaxGeight;

	TArray<AGridBaseActor*> SceneGridList;
};
