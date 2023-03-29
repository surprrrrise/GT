// Fill out your copyright notice in the Description page of Project Settings.


#include "TFGameInstance.h"


AGridManagerActor* AGridManagerActor::GridManagerActor = nullptr;

UTFGameInstance::UTFGameInstance()
{
}

void UTFGameInstance::StartGameInstance()
{
	Super::StartGameInstance();

	GridManager = AGridManagerActor::GetInstance();

}

FGameInstancePIEResult UTFGameInstance::StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params)
{
	FGameInstancePIEResult StartResult = Super::StartPlayInEditorGameInstance(LocalPlayer, Params);
	UE_LOG(LogTemp, Warning, TEXT("StartPlayInEditorGameInstance :Create Singleton"));
	GridManager = AGridManagerActor::GetInstance();
	return StartResult;
}
