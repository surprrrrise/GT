// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharactor.h"

// Sets default values
AEnemyCharactor::AEnemyCharactor()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharactor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharactor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HP < 0)
	{
		Dead();
	}

}

// Called to bind functionality to input
void AEnemyCharactor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

void AEnemyCharactor::Dead()
{

}

