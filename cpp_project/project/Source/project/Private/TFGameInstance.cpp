// Fill out your copyright notice in the Description page of Project Settings.


#include "TFGameInstance.h"
PRAGMA_DISABLE_OPTIMIZATION

AGridManagerActor* AGridManagerActor::GridManagerActor = nullptr;

UTFGameInstance::UTFGameInstance()
{
}

void UTFGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

	GridManager = AGridManagerActor::Flush();

}

FGameInstancePIEResult UTFGameInstance::StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params)
{
	FGameInstancePIEResult StartResult = Super::StartPlayInEditorGameInstance(LocalPlayer, Params);
	UE_LOG(LogTemp, Warning, TEXT("StartPlayInEditorGameInstance :Create Singleton"));
	GridManager = AGridManagerActor::Flush();
	return StartResult;
}

PRAGMA_ENABLE_OPTIMIZATION