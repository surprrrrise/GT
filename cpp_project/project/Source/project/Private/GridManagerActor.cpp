// Fill out your copyright notice in the Description page of Project Settings.


#include "GridManagerActor.h"

#include "Kismet/GameplayStatics.h"

const int32 GridAdjacentInfoList[100][6] =
{
	{0,  0,  11,  2,  0,  0},
	{1,  11, 12,  3,  0,  0},
	{2,  12, 13,  4,  0,  0},
	{3,  13, 14,  5,  0,  0},
	{4,  14, 15,  6,  0,  0},
	{5,  15, 16,  7,  0,  0},
	{6,  16, 17,  8,  0,  0},
	{7,  17, 18,  9,  0,  0},
	{8,  18, 19, 10,  0,  0},
	{9,  19, 20,  0,  0,  0},

	{0,  21, 22, 12,  2,  1},
	{11, 22, 23, 13,  3,  2},
	{12, 23, 24, 14,  4,  3},
	{13, 24, 25, 15,  5,  4},
	{14, 25, 26, 16,  6,  5},
	{15, 26, 27, 17,  7,  6},
	{16, 27, 28, 18,  8,  7},
	{17, 28, 29, 19,  9,  8},
	{18, 29, 30, 20, 10,  9},
	{19, 30,  0,  0,  0, 10},

	{ 0,  0, 31, 22, 11,  0},
	{21, 31, 32, 23, 12, 11},
	{22, 32, 33, 24, 13, 12},
	{23, 33, 34, 25, 14, 13},
	{24, 34, 35, 26, 15, 14},
	{25, 35, 36, 27, 16, 15},
	{26, 36, 37, 28, 17, 16},
	{27, 37, 38, 29, 18, 17},
	{28, 38, 39, 30, 19, 18},
	{29, 39, 40,  0, 20, 19},

	{ 0, 41, 42, 32, 22, 21},
	{31, 42, 43, 33, 23, 22},
	{32, 43, 44, 34, 24, 23},
	{33, 44, 45, 35, 25, 24},
	{34, 45, 46, 36, 26, 25},
	{35, 46, 47, 37, 27, 26},
	{36, 47, 48, 38, 28, 27},
	{37, 48, 49, 39, 29, 28},
	{38, 49, 50, 40, 30, 29},
	{39, 50,  0,  0,  0, 30},

	{ 0,  0, 51, 42, 31,  0},
	{41, 51, 52, 43, 32, 31},
	{42, 52, 53, 44, 33, 32},
	{43, 53, 54, 45, 34, 33},
	{44, 54, 55, 46, 35, 34},
	{45, 55, 56, 47, 36, 35},
	{46, 56, 57, 48, 37, 36},
	{47, 57, 58, 49, 38, 37},
	{48, 58, 59, 50, 39, 38},
	{49, 59, 60,  0, 40, 39},

	{ 0, 61, 62, 52, 42, 41},
	{51, 62, 63, 53, 43, 42},
	{52, 63, 64, 54, 44, 43},
	{53, 64, 65, 55, 45, 44},
	{54, 65, 66, 56, 46, 45},
	{55, 66, 67, 57, 47, 46},
	{56, 67, 68, 58, 48, 47},
	{57, 68, 69, 59, 49, 48},
	{58, 69, 70, 60, 50, 49},
	{59, 70,  0,  0,  0, 50},

	{ 0,  0, 71, 62, 51,  0},
	{61, 71, 72, 63, 52, 51},
	{62, 72, 73, 64, 53, 52},
	{63, 73, 74, 65, 54, 53},
	{64, 74, 75, 66, 55, 54},
	{65, 75, 76, 67, 56, 55},
	{66, 76, 77, 68, 57, 56},
	{67, 77, 78, 69, 58, 57},
	{68, 78, 79, 80, 59, 58},
	{69, 79, 80,  0, 60, 59},

	{ 0, 81, 82, 72, 62, 61},
	{71, 82, 83, 73, 63, 62},
	{72, 83, 84, 74, 64, 63},
	{73, 84, 85, 75, 65, 64},
	{74, 85, 86, 76, 66, 65},
	{75, 86, 87, 77, 67, 66},
	{76, 87, 88, 78, 68, 67},
	{77, 88, 89, 79, 69, 68},
	{78, 89, 90, 80, 70, 69},
	{79, 90,  0,  0,  0, 70},

	{ 0,  0, 91, 82, 71,  0},
	{81, 91, 92, 83, 72, 71},
	{82, 92, 93, 84, 73, 72},
	{83, 93, 94, 85, 74, 73},
	{84, 94, 95, 86, 75, 74},
	{85, 95, 96, 87, 76, 75},
	{86, 96, 97, 88, 77, 76},
	{87, 97, 98, 89, 78, 77},
	{88, 98, 99, 90, 79, 78},
	{89, 99, 100, 0, 80, 79},

	{ 0, 0, 0, 92, 82, 81},
	{91, 0, 0, 93, 83, 82},
	{92, 0, 0, 94, 84, 83},
	{93, 0, 0, 95, 85, 84},
	{94, 0, 0, 96, 86, 85},
	{95, 0, 0, 97, 87, 86},
	{96, 0, 0, 98, 88, 87},
	{97, 0, 0, 99, 89, 88},
	{98, 0, 0, 100,90, 89},
	{99, 0, 0, 0,  0,  90},

};

AGridManagerActor* AGridManagerActor::GridManagerActor = nullptr;

// Sets default values
AGridManagerActor::AGridManagerActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGridManagerActor::BeginPlay()
{
	Super::BeginPlay();
	
	//	����Grid
	BuildLevel();
}

// Called every frame
void AGridManagerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGridManagerActor::BuildLevel()
{
	//	�Ȼ�ȡ�����������е�grid base
	TArray<AActor*> GridActorArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGridBaseActor::StaticClass(), GridActorArray);

	TMap<int32, AGridBaseActor*> TempMappingMap;
	//	��������actor
	//		��һ����Ҫ���ж���Щgrid����
	for (AActor* Actor : GridActorArray)
	{
		//	�Ƚ�������ת��
		AGridBaseActor* Grid = Cast<AGridBaseActor>(Actor);

		//	������
		TempMappingMap.Add(TTuple<int32, AGridBaseActor*>(Grid->GridNum, Grid));

		GridList.Add(Grid);
	}

	//	�ٱ���һ��
	for (AActor* Actor : GridActorArray)
	{
		//	�Ƚ�������ת��
		AGridBaseActor* Grid = Cast<AGridBaseActor>(Actor);

		auto AdjacentInfo = GridAdjacentInfoList[Grid->GridNum - 1];

		FGridAdjacentInfo TempNode{};

		//	��һ�ж�
		if (AdjacentInfo[0] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[0]))
			{
				TempNode.Up = TempMappingMap[AdjacentInfo[0]];
			}
		}
		if (AdjacentInfo[1] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[1]))
			{
				TempNode.Up_Right = TempMappingMap[AdjacentInfo[1]];
			}
		}
		if (AdjacentInfo[2] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[1]))
			{
				TempNode.Down_Right = TempMappingMap[AdjacentInfo[1]];
			}
		}
		if (AdjacentInfo[3] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[1]))
			{
				TempNode.Down = TempMappingMap[AdjacentInfo[1]];
			}
		}
		if (AdjacentInfo[4] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[1]))
			{
				TempNode.Down_Left = TempMappingMap[AdjacentInfo[1]];
			}
		}
		if (AdjacentInfo[5] != 0)
		{
			//	����
			if (TempMappingMap.Contains(AdjacentInfo[1]))
			{
				TempNode.Up_Left = TempMappingMap[AdjacentInfo[1]];
			}
		}
	}
}

AGridBaseActor* AGridManagerActor::GetRelativeGrid(AGridBaseActor* grid, int32 index)
{
	auto AdjacentInfo = GridMappingMap[grid];

	if (index == 1)
		return AdjacentInfo.Up;

	if (index == 2)
		return AdjacentInfo.Up_Right;

	if (index == 3)
		return AdjacentInfo.Down_Right;

	if (index == 4)
		return AdjacentInfo.Down;

	if (index == 5)
		return AdjacentInfo.Down_Left;

	if (index == 6)
		return AdjacentInfo.Up_Left;

	return nullptr;
}

