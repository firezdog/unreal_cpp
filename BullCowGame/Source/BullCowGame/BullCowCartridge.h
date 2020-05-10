#pragma once
#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include <array>
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	private:
	void Start();
	void SelectSecretWord();
	void PrintInstructions();

	void handleGuess(const FString& Input);
	void promptToRestart(const FString& Input);

	FString secretWord;
	int numTries;
	std::array<FString, 10> secretWords = {"myth", "duck", "word", "gasp", "jinx", "wolf", "cargo", "silent", "extra", "simple"};
};
