/*
  In this game, the player is asked to guess an isogram (a word with no letters repeating).
  If the player gets the right letter in the right place, she gets a "bull";
  if she guesses the right letter in the wrong place, she gets a "cow".
  She has 10 tries to guess the correct word (winning and losing conditions).
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <map>
#include <string>

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

typedef struct {
	map<char, bool> wordMap;
	string word;
} wordInfo;

string chooseWord()
{
	return "pork";
}

map<char, bool> generateWordMap(string word)
{
	map<char, bool> wordMap;
	for (int i = 0; i < word.length(); i++) 
	{
		wordMap[word.at(i)] = true;
	}
	return wordMap;
}

wordInfo getWordInfo()
{
	wordInfo info;
	info.word = chooseWord();
	info.wordMap = generateWordMap(info.word);
	return info;
}

void askForGuess(wordInfo info)
{
	cout << "Hint: The word is " << info.word.length() << " letters.\n";
	string guess;
	cin >> guess;
	cout << "You guessed \"" << guess << "\".\n";
	for (int i = 0; i < guess.length(); i++)
	{
		cout << info.wordMap[guess.at(i)] << "\n";
	}
	if (guess == info.word)
	{
		cout << "Congratulations -- you are correct!\n";
		return;
	}
	else cout << "Sorry, try again...\n";
}

void gameLoop()
{
	while (true)
	{
		wordInfo info = getWordInfo();
		askForGuess(info);
	}
}

int main()
{
	printIntro();
	gameLoop();
	return 0;
}