// Fill out your copyright notice in the Description page of Project Settings.


#include "TFGameModeBase.h"

#include "Public/RoleBaseActor.h"
#include "TFPlayerController.h"

ATFGameModeBase::ATFGameModeBase() : AGameModeBase()
{
    ////	设置Player Controller
    //PlayerControllerClass = ATFPlayerController::StaticClass();

    // 设置玩家角色
    //static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/BP/Role/BP_Role.BP_Role'"));
    //if (PlayerPawnBPClass.Class != NULL)
    //{
    //    DefaultPawnClass = ARoleBaseActor::StaticClass();
    //    PlayerControllerClass = ATFPlayerController::StaticClass();
    //}



}

