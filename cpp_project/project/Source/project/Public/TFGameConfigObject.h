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
	//	ÿ֡����Sanֵ����ֵ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float RoleSanDeltaValue;

	//	�������ɿ�Խ�߶�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float RoleCrossGridMaxGeight;

	//	������ɢ�ĳ���ʱ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|Global")
	float FogDisableTime;

};
