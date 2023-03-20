// Fill out your copyright notice in the Description page of Project Settings.


#include "RoleBaseActor.h"

#include <Kismet/GameplayStatics.h>
#include <Kismet/KismetMathLibrary.h>

#include "GridManagerActor.h"

// Sets default values
ARoleBaseActor::ARoleBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARoleBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	启用用户输入
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		EnableInput(PC);

		InputComponent->BindAction("Up", EInputEvent::IE_Pressed, this, &ARoleBaseActor::UpPress);
		InputComponent->BindAction("Down", EInputEvent::IE_Pressed, this, &ARoleBaseActor::DownPress);
		InputComponent->BindAction("Right", EInputEvent::IE_Pressed, this, &ARoleBaseActor::RightPress);
		InputComponent->BindAction("Left", EInputEvent::IE_Pressed, this, &ARoleBaseActor::LeftPress);
	}
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
			return;
		}
		if (inputType == Left)
		{
			inputType = Left_Up;
			return;
		}
		inputType = Up;
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
			return;
		}
		if (inputType == Left)
		{
			inputType = Left_Down;
			return;
		}
		inputType = Down;
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
		inputType = Right;
	}
}

void ARoleBaseActor::Move()
{
	AGridBaseActor* TargetActor = nullptr;
	switch (inputType)
	{
	case ARoleBaseActor::Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 1);
		break;
	case ARoleBaseActor::Right_Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 2);
		break;
	case ARoleBaseActor::Right_Down:		
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 3);
		break;
	case ARoleBaseActor::Down:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 4);
		break;
	case ARoleBaseActor::Left_Down:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 5);
		break;
	case ARoleBaseActor::Left_Up:
		TargetActor = AGridManagerActor::GetInstance()->GetRelativeGrid(GetCurrentGrid(), 6);
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
		auto CurrentLocation = this->GetTransform().GetLocation();

		MoveDirection = TargetLocation - CurrentLocation;
		MoveDirection.Normalize(0.0001);

		isMoving = true;
	}
	inputType = None;
}

AGridBaseActor* ARoleBaseActor::GetCurrentGrid()
{
	return nullptr;
}

