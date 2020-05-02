/*
  In this game, the player is asked to guess an isogram (a word with no letters repeating).
  If the player gets the right letter in the right place, she gets a "bull";
  if she guesses the right letter in the wrong place, she gets a "cow".
  She has 10 tries to guess the correct word (winning and losing conditions).
*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

string getFileContents(ifstream &file)
{
	string lines = "";
	if (file)
	{
		while (file.good())
		{
			string nextline;
			getline(file, nextline);
			nextline += "\n";
			lines += nextline;
		}
		return lines;
	}
	else
	{
		return "ERROR: file not found.";
	}
}

void printIntro()
{
	ifstream Reader("bull_cow.txt");
	string intro = getFileContents(Reader);
	cout << intro << endl;
}

void gameLoop()
{
	while (true)
	{
		string word = "pork";
		map<char, bool> wordMap;
		for (int i = 0; i < word.length(); i++) 
		{
			wordMap[word.at(i)] = true;
		}
		cout << "Hint: The word is 4 letters.\n";
		string guess;
		cin >> guess;
		cout << "You guessed \"" << guess << "\".\n";
		for (int i = 0; i < guess.length(); i++)
		{
			cout << wordMap[guess.at(i)] << "\n";
		}
		if (guess == "pork")
		{
			cout << "Congratulations -- you are correct!\n";
			return;
		}
		else
			cout << "Sorry, try again...\n";
	}
}

int main()
{
	printIntro();
	gameLoop();
	return 0;
}