#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintInstructions();
    UBullCowCartridge::Start();
}

void UBullCowCartridge::Start()
{
    numTries = 3;
    SelectSecretWord();
    PrintLine(TEXT("The secret word is " + FString::FromInt(secretWord.Len()) + " letters."));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (numTries > 0)
    {
        handleGuess(Input);
    }
    else
    {
        promptToRestart(Input);
    }
}

void UBullCowCartridge::handleGuess(const FString& Input)
{
    if (Input.ToLower() == secretWord)
    {
        PrintLine(TEXT("You got it!"));
        PrintLine("Please enter \"restart\" to restart the game.");
        numTries = 0;
    }
    else
    {
        numTries -= 1;
        if (numTries > 0)
        {
            PrintLine(TEXT("Try again..."));
            PrintLine(TEXT("You have " + FString::FromInt(numTries) + " tries left."));
        }
        else promptToRestart(Input);
    }
}

void UBullCowCartridge::promptToRestart(const FString& Input)
{
    if (Input.ToLower() == "restart") 
    {
        Start();
    }
    else PrintLine("Please enter \"restart\" to restart the game.");
}


void UBullCowCartridge::SelectSecretWord()
{
    int selectionIndex = FMath::RandRange(0, std::size(secretWords) - 1);
    secretWord = secretWords[selectionIndex];
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