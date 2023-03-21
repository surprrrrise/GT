// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TFGameConfigObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROJECT_API UTFGameConfigObject : public UObject
{
	GENERATED_BODY()

public:
	//	每帧人物San值掉落值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float RoleSanDeltaValue;

	//	人物最大可跨越高度
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float RoleCrossGridMaxGeight;

	//	雾气消散的持续时间
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float FogDisableTime;

};
