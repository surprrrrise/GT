// Fill out your copyright notice in the Description page of Project Settings.


#include "RoleBaseActor.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

#include "GridManagerActor.h"
#include "TFGlobalConfigActor.h"

PRAGMA_DISABLE_OPTIMIZATION

// Sets default values
ARoleBaseActor::ARoleBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
	
	//	����Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Role"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARoleBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	��ȡȫ���趨
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATFGlobalConfigActor::StaticClass());
	ATFGlobalConfigActor* GLobalSetting = Cast<ATFGlobalConfigActor>(Actor);
	SanDeltaValue = GLobalSetting->RoleSanDeltaValue;
	CrossGridMaxGeight = GLobalSetting->RoleCrossGridMaxGeight;

	//	�����û�����
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		EnableInput(PC);

		InputComponent->BindAction("Up", EInputEvent::IE_Pressed, this, &ARoleBaseActor::UpPress);
		InputComponent->BindAction("Down", EInputEvent::IE_Pressed, this, &ARoleBaseActor::DownPress);
		InputComponent->BindAction("Right", EInputEvent::IE_Pressed, this, &ARoleBaseActor::RightPress);
		InputComponent->BindAction("Left", EInputEvent::IE_Pressed, this, &ARoleBaseActor::LeftPress);

		InputComponent->BindAction("OpenFog", EInputEvent::IE_Pressed, this, &ARoleBaseActor::OpenFog);
	}

	SceneGridList = GetGridList();
	CurrentGrid = GetCurrentGrid(SceneGridList);

	
	auto SelfLocation = this->GetTransform().GetLocation();
	auto GridLocation = CurrentGrid->GetActorLocation();

	CurrentSanValue = SanValue;
}

// Called every frame
void ARoleBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isMoving)
	{
		auto Transform = this->GetTransform();
		auto Location = Transform.GetLocation() + (Velocity * MoveDirection);
		Transform.SetLocation(Location);
		this->SetActorTransform(Transform);

		//	�ж��Ƿ�ֹͣ
		if (UKismetMathLibrary::Dot_VectorVector((TargetLocation - Location), MoveDirection) < 0.)
		{
			isMoving = false;
			CurrentGrid = GetCurrentGrid(SceneGridList);
			AGridManagerActor::GetInstance()->SetCurrentGrid(CurrentGrid, SceneGridList);

			//	����λ��
			TargetLocation = CurrentGrid->GetTransform().GetLocation();

			auto NewPos = FVector{ TargetLocation.X, TargetLocation.Y, TargetLocation.Z + 9999. };
			FHitResult HitRes{};

			//	�ƶ�����ǰ��grid��grid�п��ܻ���Σ���ʱ������Ҫ�ж�һ�²�����ɫ�����ƶ�
			if (GetWorld()->LineTraceSingleByChannel(HitRes, NewPos, TargetLocation, ECC_GameTraceChannel1))
			{
				TargetLocation = HitRes.Location;
			}
			//auto CurrentLocation = this->GetTransform().GetLocation();

			SetActorLocation(TargetLocation);

			MoveDirection = FVector::Zero();
		}
	}

	//	�ж��Ƿ��sanֵ
	if (CurrentGrid->GetFogStatus())
	{
		CurrentSanValue -= SanDeltaValue;
	}

	//	sanֵ���ͣ�����
	if (CurrentSanValue < 0.)
	{
		Dead();
	}
}

void ARoleBaseActor::Dead()
{
}

void ARoleBaseActor::OpenFog()
{
	CurrentGrid->SetFogStatus(false);

	AGridBaseActor* RelativeGrid = nullptr;
	for (size_t i = 1; i <= 6; ++i)
	{
		RelativeGrid = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, i, SceneGridList);
		if (RelativeGrid != nullptr)
		{
			RelativeGrid->SetFogStatus(false);
		}
	}
}

void ARoleBaseActor::UpPress()
{
	if (!isMoving)
	{
		if (inputType == Right)
		{
			inputType = Right_Up;
		}
		if (inputType == Left)
		{
			inputType = Left_Up;
		}
		if (inputType == None)
		{
			inputType = Up;
		}
		Move();
	}
}

void ARoleBaseActor::DownPress()
{
	if (!isMoving)
	{
		if (inputType == Right)
		{
			inputType = Right_Down;
		}
		if (inputType == Left)
		{
			inputType = Left_Down;
		}
		if (inputType == None)
		{
			inputType = Down;
		}
		Move();
	}
}

void ARoleBaseActor::RightPress()
{
	if (!isMoving)
	{
		inputType = Right;
	}
}

void ARoleBaseActor::LeftPress()
{
	if (!isMoving)
	{
		inputType = Left;
	}
}

void ARoleBaseActor::Move()
{
	AGridBaseActor* TargetActor = nullptr;
	switch (inputType)
	{
	case ARoleBaseActor::Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 1, SceneGridList);
		break;
	case ARoleBaseActor::Right_Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 2, SceneGridList);
		break;
	case ARoleBaseActor::Right_Down:		
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 3, SceneGridList);
		break;
	case ARoleBaseActor::Down:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 4, SceneGridList);
		break;
	case ARoleBaseActor::Left_Down:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 5, SceneGridList);
		break;
	case ARoleBaseActor::Left_Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(CurrentGrid, 6, SceneGridList);
		break;
	case Right:
	case Left:
	case None:
	default:
		break;
	}
	if (TargetActor)
	{
		TargetLocation = TargetActor->GetTransform().GetLocation();

		const auto NewPos = FVector{ TargetLocation.X, TargetLocation.Y, TargetLocation.Z + 9999. };
		FHitResult HitRes{};

		//	���ж�Ҫ�ƶ�����grid�ĸ߶�
		if (GetWorld()->LineTraceSingleByChannel(HitRes, NewPos, TargetLocation, ECC_GameTraceChannel1))
		{
			TargetLocation = HitRes.Location;
		}
		const auto CurrentLocation = this->GetTransform().GetLocation();
		if (abs(TargetLocation.Z - CurrentLocation.Z) <= CrossGridMaxGeight)
		{
			MoveDirection = TargetLocation - CurrentLocation;
			MoveDirection.Normalize(0.0001);

			isMoving = true;
		}
		else
		{
			isMoving = false;
			MoveDirection = FVector::Zero();
		}
	}
	inputType = None;
}

AGridBaseActor* ARoleBaseActor::GetCurrentGrid(TArray<AGridBaseActor*>& GridList)
{
	//auto& GridList = AGridManagerActor::GetInstance()->GridList;

	auto CurrentLocation = this->GetTransform().GetLocation();

	int32 index = -1;
	float MinDistance = 9999;

	for (size_t i = 0; i < GridList.Num(); ++i)
	{
		auto TempLocation = GridList[i]->GetTransform().GetLocation();
		auto Distance = (TempLocation - CurrentLocation).Length();

		if (MinDistance > Distance)
		{
			MinDistance = Distance;
			index = i;
		}
	}

	if(index == -1) return nullptr;

	return GridList[index];
}

TArray<AGridBaseActor*> ARoleBaseActor::GetGridList()
{
	TArray<AGridBaseActor*> res;
	//	�Ȼ�ȡ�����������е�grid base
	TArray<AActor*> GridActorArray;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Grid"), GridActorArray);

	TMap<int32, AGridBaseActor*> TempMappingMap;
	//	��������actor
	//		��һ����Ҫ���ж���Щgrid����
	for (AActor* Actor : GridActorArray)
	{
		//	�Ƚ�������ת��
		AGridBaseActor* Grid = Cast<AGridBaseActor>(Actor);

		
		res.Add(Grid);
	}

	return res;
}

PRAGMA_ENABLE_OPTIMIZATION