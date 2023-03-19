// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "GridBaseActor.h"

#include "LevelDesignAsset.generated.h"

//UCLASS(BlueprintType, Category = "TF|LevelDesign")
//class GridOperatorFunc : public UObject
//{
//	GENERATED_BODY()
//public:
//	virtual bool Operator(AGridBaseActor* Actor) = 0;
//};

USTRUCT(BlueprintType, Category = "TF|LevelDesign")
struct FGridInfo
{
	GENERATED_USTRUCT_BODY()

public:
	//	是否启用
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|GridInfo")
	bool isEnable;

	//	当前网格需要操作的方法
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|GridInfo")
	//TObjectPtr<GridOperatorFunc> OperatorFunc;
	bool OperatorFunc;

	//	指定Grid的Actor	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|GridInfo")
	FString GridActor;
};


/**
 * 
 */
UCLASS()
class PROJECT_API ULevelDesignAsset : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo5;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo6;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo7;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo9;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo12;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo13;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo14;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo15;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo16;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo17;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo18;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo19;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo20;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo21;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo22; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo23;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo24;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo25;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo26;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo27;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo28;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo29;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo30;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo31;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo32;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo33;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo34;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo35;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo36;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo37;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo38;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo39;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo40;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo41;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo42;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo43;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo44;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo45;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo46;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo47;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo48;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo49;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo51;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo52;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo53;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo54;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo55;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo56;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo57;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo58;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo59;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo60;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo61;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo62;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo63;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo64;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo65;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo66;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo67;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo68;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo69;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo70;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo71;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo72;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo73;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo74;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo75;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo76; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo77;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo78;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo79;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo80;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo81;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo82;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo83;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo84;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo85;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo86;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo87;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo88;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo89;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo90;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo91;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo92;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo93;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo94;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo95;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo96;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo97;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo98;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo99;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TF|LevelDesign|Asset")
	FGridInfo GridInfo100;

};
