// Fill out your copyright notice in the Description page of Project Settings.



#include "GridBaseActor.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

#include "TFGlobalConfigActor.h"

// Sets default values
AGridBaseActor::AGridBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//	创建Mesh
	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Grid_Mesh"));
	GridMesh->SetupAttachment(RootComponent);
	FogMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fog_Mesh"));
	FogMesh->SetupAttachment(RootComponent);

	//auto ActorTrans = GetTransform();
	//auto FogTrans = UKismetMathLibrary::ComposeTransforms(FogRelativeTransform, GetTransform());
	//FogMesh->SetWorldTransform(FogTrans);
}

// Called when the game starts or when spawned
void AGridBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	获取全局设定
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATFGlobalConfigActor::StaticClass());
	ATFGlobalConfigActor* GLobalSetting = Cast<ATFGlobalConfigActor>(Actor);
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

