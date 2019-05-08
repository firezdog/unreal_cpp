#include <iostream>
#include <cstdlib>

using namespace std; 

int* getNumbers(int difficulty) {
  srand((unsigned)time(0));
  static int numbers[3];
  for (int i = 0; i < 3; i++) {
    numbers[i] = rand() % difficulty;
  }
  return numbers;
}

void writeWelcome(int difficulty) {
  std::cout << "Welcome to the number game.\n";
  std::cout << "You have selected difficulty level "; 
  std::cout << difficulty << "\n";
}

void printPuzzle(int* numbers) {
  int sum = 0;
  int product = 1;
  for (int i = 0; i < 3; i++) {
    int number = (*numbers + i);
    sum += number;
    product *= number;
  }
  std::cout << "Find three numbers whose product is " << product << " and whose sum is " << sum << endl;
}

void playGameAtDifficulty(int difficulty) {
  writeWelcome(difficulty);
  int* numbers = getNumbers(difficulty);
  printPuzzle(numbers);
}

int main(int argc, char **argv)
{
  int difficulty = std::stoi(argv[1]);
  playGameAtDifficulty(difficulty);
  return 0;
}