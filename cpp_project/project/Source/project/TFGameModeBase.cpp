// Fill out your copyright notice in the Description page of Project Settings.


#include "TFGameModeBase.h"

#include "TFPlayerController.h"

ATFGameModeBase::ATFGameModeBase() : AGameModeBase()
{
	//	����Player Controller
	PlayerControllerClass = ATFPlayerController::StaticClass();
}
