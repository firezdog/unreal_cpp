/* 
  In this game, the player is asked to guess an isogram (a word with no letters repeating). If the player gets the right letter in the right place, she gets a "bull"; if she guesses the right letter in the wrong place, she gets a "cow". She has 10 tries to guess the correct word (winning and losing conditions).
*/

#include <iostream>
#include <fstream>

// so nice! Now I don't have to use char* :)
#include <string>

using namespace std;

string getFileContents(ifstream &file) {
  string lines = "";
  if (file) {
    while (file.good()) {
      string nextline;
      getline(file, nextline);
      nextline += "\n";
      lines += nextline;
    }
    return lines;
  }
  else {
    return "ERROR: file not found.";
  }
}

void printIntro() {
  ifstream Reader ("bull_cow.txt");
  string intro = getFileContents(Reader);
  cout << intro << endl;
}

int main() {
  printIntro();
  return 0;
}