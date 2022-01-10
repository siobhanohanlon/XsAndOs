#include <stdio.h>

//Declare Variables
char squares[10] = {'0','1','2','3','4','5','6','7','8','9'};

//Define Functions
void NewGame();
void ContinueGame();
void PlayGame();
void SaveGame();
int CheckWin();

void main()
{
	int gameChoice;

	printf("\t\t Welcome to Xs & Os\n\n");
	printf("\tPlayer 1: X\t\tPlayer 2: O\n\n");

	printf("\nPlease Enter 1 to Load a Saved Game or any Other Number to Start a New Game:\t");
	scanf("%d", &gameChoice);

	if (gameChoice == 1)
	{
		//Go to Load Game Function
		ContinueGame();
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

	//Create the Board
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[0], squares[1], squares[2]);
	printf("\t   _________|_________|_________\n");
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[4], squares[5], squares[6]);
	printf("\t   _________|_________|_________\n");
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[7], squares[8], squares[9]);
	printf("\t\t    |         |\n");

	PlayGame(player);
}

void PlayGame();

//Check if Game is Won
CheckWin();