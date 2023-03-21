// Fill out your copyright notice in the Description page of Project Settings.



#include "GridBaseActor.h"

#include <Kismet/GameplayStatics.h>
#include "TFGameConfigObject.h"

// Sets default values
AGridBaseActor::AGridBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	创建Mesh
	FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fog_Mesh"));
	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_Mesh"));

}

// Called when the game starts or when spawned
void AGridBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	获取全局设定
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), UTFGameConfigObject::StaticClass());
	UTFGameConfigObject* GLobalSetting = Cast<UTFGameConfigObject>(Actor);
	FogDisableTime = GLobalSetting->FogDisableTime;
}

// Called every frame
void AGridBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!isFogEnable)
	{
		CurFogDisableTime -= 1.f;

		if (CurFogDisableTime < 0.f)
		{
			SetFogStatus(true);
			CurFogDisableTime = FogDisableTime;
			isFogEnable = true;
		}
	}
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

