// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TFGlobalConfigActor.generated.h"

UCLASS()
class PROJECT_API ATFGlobalConfigActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATFGlobalConfigActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//	雾气消散的持续时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
		float FogDisableTime;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		float RoleVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		float RoleSanValue;

	//	每帧人物San值掉落值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		float RoleSanDeltaValue;

	//	人物最大可跨越高度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		float RoleCrossGridMaxGeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		TSubclassOf<UUserWidget> RoleWinWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Role")
		TSubclassOf<UUserWidget> RoleLoseWidget;
};
