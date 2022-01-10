#include <stdio.h>

//Declare Variables
char squares[10] = {'0','1','2','3','4','5','6','7','8','9'};

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

	printf("Please Enter 1 to Load a Saved Game or any Other Number to Start a New Game:\t");
	scanf("%d", &gameChoice);

	printf("\n\t\t Welcome to Xs & Os\n\n");
	printf("\tPlayer 1: X\t\tPlayer 2: O\n\n");

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

	//Create the Board
	CreateBoard();

	PlayGame(player);
}

//Create Board
void CreateBoard()
{
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[0], squares[1], squares[2]);
	printf("\t   _________|_________|_________\n");
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[4], squares[5], squares[6]);
	printf("\t   _________|_________|_________\n");
	printf("\t\t    |         |\n");
	printf("\t       %c    |    %c    |    %c\n", squares[7], squares[8], squares[9]);
	printf("\t\t    |         |\n");
}

//Play Game
void PlayGame(int player)
{
	char mark;
	int won, choice;

	do {
		printf("\n\nSelect a Square Number\n");
		printf("Player %ds Turn:", player);
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

		//Update Board
		CreateBoard();

		//Check if Game Won
		won = CheckWin();
	} while (won == -1);

	EndOfGame(won);
}

//Check for Win
int CheckWin()
{
	//HorizontalLine
	for (int i = 0; i < 9; i + 3)
	{
		if (squares[i] == squares[i + 1] == squares[i + 2])
		{
			return 1;
		}
	}

	//VerticalLine
	for (int i = 0; i < 3; i++)
	{
		if (squares[i] == squares[i + 3] == squares[i + 3])
		{
			return 1;
		}
	}

	//DiagonalLine
	for (int i = 0; i < 2; i + 3)
	{
		if (squares[i] == squares[i + 4] == squares[i + 4])
		{
			return 1;
		}
	}

	//Draw
	if (squares[0] != '1' && squares[1] != '2' && squares[2] != '3'
		&& squares[3] != '4' && squares[4] != '5' && squares[5] != '6'
		&& squares[6] != '7' && squares[7] != '8' && squares[8] != '9')
	{
		return 0;
	}

	//Keep Playing
	else
	{
		return -1;
	}
}

//End of Game
void EndOfGame()
{

}