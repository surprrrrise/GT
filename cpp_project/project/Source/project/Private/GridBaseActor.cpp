// Fill out your copyright notice in the Description page of Project Settings.



#include "GridBaseActor.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

#include "TFGlobalConfigActor.h"

PRAGMA_DISABLE_OPTIMIZATION

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
	HintMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Hint_Mesh"));
	HintMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/Mesh/Tiles/Blank/blank_hint.blank_hint'"));
	static ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> ConstHintNormalMaterial(TEXT("MaterialInstanceConstant'/Game/Material/Grid/MI_hint_normal.MI_hint_normal'"));
	static ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> ConstHintSelectedMaterial(TEXT("MaterialInstanceConstant'/Game/Material/Grid/MI_hint_highlight.MI_hint_highlight'"));
	HintNormalMaterial = ConstHintNormalMaterial.Get();
	HintSelectedMaterial = ConstHintSelectedMaterial.Get();
	if (MeshComponentAsset.Succeeded())
	{
		HintMesh->SetStaticMesh(MeshComponentAsset.Object);
		HintMesh->SetMaterial(0, HintNormalMaterial);
	}
}

// Called when the game starts or when spawned
void AGridBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	获取全局设定
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATFGlobalConfigActor::StaticClass());
	ATFGlobalConfigActor* GLobalSetting = Cast<ATFGlobalConfigActor>(Actor);
	FogDisableTime = GLobalSetting->FogDisableTime;

	CurFogDisableTime = FogDisableTime;
	//	设置提示
	HintMesh->SetVisibility(false);
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
		FogMesh->SetVisibility(true, true);
	}
	else
	{
		FogMesh->SetVisibility(false, true);
	}
	isFogEnable = flag;
}

void AGridBaseActor::Deform()
{
	if (GridInteractionInfo.isEnable)
	{
		auto transform = GridMesh->GetRelativeTransform();
		auto Scale = transform.GetScale3D();

		Scale.Y *= GridInteractionInfo.Size;
		transform.SetScale3D(Scale);
		GridMesh->SetRelativeTransform(transform);
		HintMesh->SetRelativeTransform(transform);

		isDeform = true;
		HeightInfo = GridInteractionInfo.Size;
	}
}

void AGridBaseActor::SetCanAttacking()
{
	HintMesh->SetVisibility(true);
}

void AGridBaseActor::SetSelected()
{
	HintMesh->SetMaterial(0, HintSelectedMaterial);
}

void AGridBaseActor::SetUnSelected()
{
	HintMesh->SetMaterial(0, HintNormalMaterial);
}

void AGridBaseActor::ResetSelected()
{
	HintMesh->SetMaterial(0, HintNormalMaterial);

	HintMesh->SetVisibility(false);
}

PRAGMA_ENABLE_OPTIMIZATION