#include <iostream>

using namespace std;

//Declare Variables
char squares[9];

//Define Functions
void NewGame();
void CreateBoard();
//void ContinueGame();
void PlayGame();
//void SaveGame();
void EndOfGame();
int CheckWin();

void main()
{
	int gameChoice;

	cout << "Please Enter 1 to Load a Saved Game or any Other Number to Start a New Game:\t";
	cin >> gameChoice;

	cout << "\n\t\t Welcome to Xs & Os\n\n";
	cout << "\tPlayer 1: X\t\tPlayer 2: O\n\n";

	if (gameChoice == 1)
	{
		//Go to Load Game Function
		//ContinueGame();
	}
	else
	{
		//Start a New Game
		NewGame();
	}
}

//NewGame
void NewGame()
{
	//Declare Variables
	int player = 1;

	cout << player;

	//Reset Square Array
	for (int sq = 0; sq < 9; sq++)
	{
		squares[sq] = (sq + 1);
	}

	//Create the Board
	CreateBoard();

	PlayGame();
}
