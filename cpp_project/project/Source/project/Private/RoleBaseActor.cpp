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
	
	//	创建Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Role"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARoleBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	获取全局设定
	auto Actor = UGameplayStatics::GetActorOfClass(GetWorld(), ATFGlobalConfigActor::StaticClass());
	ATFGlobalConfigActor* GLobalSetting = Cast<ATFGlobalConfigActor>(Actor);
	SanDeltaValue = GLobalSetting->RoleSanDeltaValue;
	CrossGridMaxGeight = GLobalSetting->RoleCrossGridMaxGeight;

	//	启用用户输入
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

		//	判断是否停止
		if (UKismetMathLibrary::Dot_VectorVector((TargetLocation - Location), MoveDirection) < 0.)
		{
			isMoving = false;
			CurrentGrid = GetCurrentGrid(SceneGridList);
			AGridManagerActor::GetInstance()->SetCurrentGrid(CurrentGrid, SceneGridList);

			//	设置位置
			TargetLocation = CurrentGrid->GetTransform().GetLocation();

			auto NewPos = FVector{ TargetLocation.X, TargetLocation.Y, TargetLocation.Z + 9999. };
			FHitResult HitRes{};

			//	移动到当前的grid后grid有可能会变形，这时我们需要判断一下并将角色进行移动
			if (GetWorld()->LineTraceSingleByChannel(HitRes, NewPos, TargetLocation, ECC_GameTraceChannel1))
			{
				TargetLocation = HitRes.Location;
			}
			//auto CurrentLocation = this->GetTransform().GetLocation();

			SetActorLocation(TargetLocation);

			MoveDirection = FVector::Zero();
		}
	}

	//	判断是否掉san值
	if (CurrentGrid->GetFogStatus())
	{
		CurrentSanValue -= SanDeltaValue;
	}

	//	san值过低，死亡
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

		//	先判断要移动到的grid的高度
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
	//	先获取到场景中所有的grid base
	TArray<AActor*> GridActorArray;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("Grid"), GridActorArray);

	TMap<int32, AGridBaseActor*> TempMappingMap;
	//	遍历所有actor
	//		这一遍主要是判断哪些grid存在
	for (AActor* Actor : GridActorArray)
	{
		//	先进行类型转换
		AGridBaseActor* Grid = Cast<AGridBaseActor>(Actor);

		
		res.Add(Grid);
	}

	return res;
}

PRAGMA_ENABLE_OPTIMIZATION