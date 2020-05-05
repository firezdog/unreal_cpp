// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("Hello world!"));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{

}