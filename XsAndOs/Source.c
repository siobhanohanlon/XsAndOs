#include <stdio.h>

//Declare Variables
char squares[10] = {'0','1','2','3','4','5','6','7','8','9'};

//Define Functions
void NewGame();
void ContinueGame();
void PlayGame();
void SaveGame();
void EndOfGame();
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

//Play Game
void PlayGame(int player, int choice)
{
	char mark;
	int won, choice;

	do {
		printf("\n\nSelect a Square Number\n");
		printf("Player %ds Turn:\n");
		scanf("%d", &choice);

		if (player == 1)
		{
			mark = 'X';
		}
		else
		{
			mark = 'O';
		}

#pragma region ChangeSquaresMark
		if (choice == 1 && squares[1] == '1')

			squares[1] = mark;
		else if (choice == 2 && squares[2] == '2')

			squares[2] = mark;
		else if (choice == 3 && squares[3] == '3')

			squares[3] = mark;
		else if (choice == 4 && squares[4] == '4')

			squares[4] = mark;
		else if (choice == 5 && squares[5] == '5')

			squares[5] = mark;
		else if (choice == 6 && squares[6] == '6')

			squares[6] = mark;
		else if (choice == 7 && squares[7] == '7')

			squares[7] = mark;
		else if (choice == 8 && squares[8] == '8')

			squares[8] = mark;
		else if (choice == 9 && squares[9] == '9')

			squares[9] = mark;
		else
		{
			printf("\n\n******Invalid Move*******");

			player--;
		}
#pragma endregion

		//Check if Game Won
		won = CheckWin();
	} while (won == -1);

	EndOfGame(won);
}
