// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Bull-Cow game."));
    PrintLine(TEXT("An isogram is a word with no repeating letters."));
    PrintLine(TEXT("You will have ten chances to guess an isogram."));
    PrintLine(TEXT("Type you guess, then press enter."));
    PrintLine(TEXT("If you are wrong, you will get a hint!"));
    PrintLine(TEXT("Press tab to start."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    PrintLine(Input);
}