#include <iostream>
#include <cstdlib>

using namespace std; 

static int rounds = 0;

int* getNumbers(int difficulty) 
{
  srand((unsigned)time(0));
  static int numbers[3];
  for (int i = 0; i < 3; i++) {
    numbers[i] = rand() % difficulty;
  }
  return numbers;
}

void writeWelcome(int difficulty) 
{
  cout 
    << "Welcome to the number game." << endl 
    << "You have selected difficulty level " 
    << difficulty << endl;
}

struct puzzle {
    int sum = 0;
    int product = 1;
};

puzzle getResults(int* numbers) {
  puzzle results;
  for (int i = 0; i < 3; i++) {
    int number = *(numbers + i);
    results.sum += number;
    results.product *= number;
  }
  return results;
}

puzzle getPuzzle(int difficulty) {
  int* numbers = getNumbers(difficulty);
  puzzle p = getResults(numbers);
  return p;
}

void printPuzzle(puzzle p) 
{
  cout 
    << "Find three integers (>= 0) whose product is " 
    << p.product 
    << " and whose sum is " 
    << p.sum << endl;
}

int* getAnswer() 
{
  static int answers[3];
  cout 
    << "Enter the three numbers below, separated by spaces." << endl;
  cin 
    >> answers[0] 
    >> answers[1] 
    >> answers[2];
  return answers;
}

bool checkAnswers(puzzle p, int* guess) {
  puzzle g = getResults(guess);
  return g.product == p.product && g.sum == p.sum;
}

void playGameAtDifficulty(int difficulty) {
  writeWelcome(difficulty);
  puzzle p = getPuzzle(difficulty);
  printPuzzle(p);
  int* guess = getAnswer();
  bool isCorrect = checkAnswers(p, guess);
  if (isCorrect) {
    cout << "You got it!" << endl;
    rounds++;
  }
  else cout << "Try again, bucko..." << endl;
}

int main(int argc, char **argv)
{
  int difficulty = stoi(argv[1]);
  while (true) {
    playGameAtDifficulty(difficulty + rounds);
    cin.clear();
    cin.ignore();
  }
  return 0;
}