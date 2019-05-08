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

void playGameAtDifficulty(int difficulty) {
  std::cout << "Welcome to the number game.\n";
  std::cout << "You have selected difficulty level "; 
  std::cout << difficulty << "\n";
  
  int* numbers;
  numbers = getNumbers(difficulty);
  std::cout << *numbers << endl;
}

int main(int argc, char **argv)
{
  int difficulty = std::stoi(argv[1]);
  playGameAtDifficulty(difficulty);
  return 0;
}