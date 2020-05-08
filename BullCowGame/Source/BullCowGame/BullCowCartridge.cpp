#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SelectSecretWord();
    PrintInstructions();
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    PrintLine(TEXT("You entered \"" + Input + "\"..."));
    if (secretWord == Input) PrintLine(TEXT("That is correct!"));
    else PrintLine(TEXT("Sorry, try again..."));
}

void UBullCowCartridge::SelectSecretWord()
{
    secretWord = TEXT("pork");
}

void UBullCowCartridge::PrintInstructions()
{
    PrintLine(TEXT("Welcome to the Bull-Cow game."));
    PrintLine(TEXT("An isogram is a word with no repeating letters."));
    PrintLine(TEXT("You will have ten chances to guess an isogram."));
    PrintLine(TEXT("Type you guess, then press enter."));
    PrintLine(TEXT("If you are wrong, you will get a hint!"));
    PrintLine(TEXT("Press tab to start."));
}