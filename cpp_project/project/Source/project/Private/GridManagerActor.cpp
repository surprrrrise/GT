// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManagerActor.h"

// Sets default values
AGridManagerActor::AGridManagerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ´´½¨
	LevelDesignAsset = CreateDefaultSubobject<ULevelDesignAsset>(TEXT("Level_Design_Asset"));

}

// Called when the game starts or when spawned
void AGridManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridManagerActor::BuildLevel()
{
	auto info = LevelDesignAsset.Get()->GridInfo1;


}

