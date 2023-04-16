// Fill out your copyright notice in the Description page of Project Settings.


#include "TFPlayerController.h"
#include "Public/RoleBaseActor.h"

PRAGMA_DISABLE_OPTIMIZATION

ATFPlayerController::ATFPlayerController() : APlayerController()
{
	//	设置游戏属性
	bShowMouseCursor = true;
	bEnableClickEvents = true;

	InputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("inputs"));
}

void ATFPlayerController::SetupInputComponent()
{
	//Super::SetupInputComponent();

	//InputComponent->BindAction("Up", EInputEvent::IE_Pressed, this, &ATFPlayerController::UpPress);
	//InputComponent->BindAction("Down", EInputEvent::IE_Pressed, this, &ARoleBaseActor::DownPress);
	//InputComponent->BindAction("Right", EInputEvent::IE_Pressed, this, &ARoleBaseActor::RightPress);
	//InputComponent->BindAction("Left", EInputEvent::IE_Pressed, this, &ARoleBaseActor::LeftPress);

	//InputComponent->BindAction("OpenFog", EInputEvent::IE_Pressed, this, &ARoleBaseActor::OpenFog);
	//InputComponent->BindAction("Attacking", EInputEvent::IE_Pressed, this, &ARoleBaseActor::Attack);

}

void ATFPlayerController::UpPress()
{
	auto Temp = GetPawn();
	auto CustomRole = Cast<ARoleBaseActor>(Temp);
}


PRAGMA_ENABLE_OPTIMIZATION