#include <iostream>

void playGameAtDifficulty(int difficulty) {
  std::cout << "Welcome to the number game.\n";
  std::cout << "You have selected difficulty level "; 
  std::cout << difficulty << "\n\n";
}

int main(int argc, char **argv)
{
  int difficulty = std::stoi(argv[1]);
  playGameAtDifficulty(difficulty);
  return 0;
}