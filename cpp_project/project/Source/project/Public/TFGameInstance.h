// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "GridManagerActor.h"

#include "TFGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UTFGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UTFGameInstance();

	virtual void StartGameInstance() override;

	virtual FGameInstancePIEResult StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params) override;

public:
	UPROPERTY(VisibleAnywhere, Category = "TF")
	TObjectPtr<AGridManagerActor> GridManager;
};
