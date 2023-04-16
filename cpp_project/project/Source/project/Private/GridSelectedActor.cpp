// Fill out your copyright notice in the Description page of Project Settings.


#include "GridSelectedActor.h"
#include <Kismet/GameplayStatics.h>

#include "GridBaseActor.h"
#include "GridManagerActor.h"
#include "EnemyCharactor.h"

// Sets default values
AGridSelectedActor::AGridSelectedActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGridSelectedActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridSelectedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (isEnableRoleAttacking)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			PC->bShowMouseCursor = true;
		}

		FHitResult Hit;
		PC->GetHitResultUnderCursor(ECC_GameTraceChannel1, false, Hit);
		if (Hit.bBlockingHit)
		{
			auto Actor = Hit.GetActor();
			AGridBaseActor* Grid = Cast<AGridBaseActor>(Actor);
			if (EnableAttackGridList.Find(Grid) || Grid == EnableAttackGridList[0])
			{
				if (SelectedGrid)
				{
					SelectedGrid->SetUnSelected();
				}
				Grid->SetSelected();
				SelectedGrid = Grid;
			}
		}

	}

}

void AGridSelectedActor::ClearSelected()
{
	for (auto& Grid : EnableAttackGridList)
	{
		Grid->ResetSelected();
	}
	isEnableRoleAttacking = false;
	EnableAttackGridList.Empty();
	SelectedGrid = nullptr;

	if (isEnableInput)
	{
		APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
		if (PC)
		{
			PC->bEnableClickEvents = false;
			InputComponent->ClearActionBindings();
		}
		isEnableInput = false;
	}
}

void AGridSelectedActor::SetHintGrid(AGridBaseActor* Target, TArray<AGridBaseActor*> SceneGridList)
{
	EnableAttackGridList.Empty();

	Target->SetCanAttacking();
	EnableAttackGridList.Add(Target);

	for (size_t i = 1; i <= 6; ++i)
	{
		if (AGridManagerActor::GetInstance()->GridList.IsEmpty())
		{
			AGridManagerActor::GetInstance()->BuildLevel(SceneGridList);
		}
		auto RelativeGrid = AGridManagerActor::GetInstance()->GetRelativeGrid(Target, i, AGridManagerActor::GetInstance()->GridList);
		if (RelativeGrid)
		{
			RelativeGrid->SetCanAttacking();
			EnableAttackGridList.Add(RelativeGrid);
		}
	}
}

void AGridSelectedActor::EnableRoleAttacking()
{
	isEnableRoleAttacking = true;

	//	启用用户输入
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		EnableInput(PC);

		//PC->bEnableClickEvents = true;
		InputComponent->BindAction("SelectGrid", EInputEvent::IE_Pressed, this, &AGridSelectedActor::SelectGrid);
		
		isEnableInput = true;
	}
}

void AGridSelectedActor::SelectGrid()
{
	if (SelectedGrid)
	{
		SelectedGrid->Deform();
	}

	auto GridLocation = SelectedGrid->GetTransform().GetLocation();
	TArray<AActor*> TargetActor;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("enemy")), TargetActor);
	for (auto& Target : TargetActor)
	{

		auto TargetLocation = Target->GetTransform().GetLocation();
		auto Length = sqrt(
			(TargetLocation.X - GridLocation.X) * (TargetLocation.X - GridLocation.X)
			+
			(TargetLocation.Y - GridLocation.Y) * (TargetLocation.Y - GridLocation.Y)
		);
		if (Length < 140)
		{
			auto Enemy = Cast<AEnemyCharactor>(Target);
			Enemy->HP -= 10;
		}
	}


	ClearSelected();
}

