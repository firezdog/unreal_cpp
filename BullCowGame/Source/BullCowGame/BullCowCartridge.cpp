// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine("Welcome to the Bull-Cow game.");
    PrintLine("An isogram is a word with no repeating letters.");
    PrintLine("You will have ten chances to guess an isogram.");
    PrintLine("Type you guess, then press enter.");
    PrintLine("If you are wrong, you will get a hint!");
    PrintLine("Press enter to start.");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
}