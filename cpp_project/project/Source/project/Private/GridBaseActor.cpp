// Fill out your copyright notice in the Description page of Project Settings.


#include "GridBaseActor.h"

// Sets default values
AGridBaseActor::AGridBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	´´½¨Mesh
	FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fog_Mesh"));
	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_Mesh"));

}

// Called when the game starts or when spawned
void AGridBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridBaseActor::SetFogStatus(bool flag)
{
	if (flag == isFogEnable) return;

	if (flag)
	{
		FogMesh->SetVisibility(true);
	}
	else
	{
		FogMesh->SetVisibility(false);
	}
	isFogEnable = flag;
}

