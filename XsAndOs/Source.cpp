#include <iostream>

using namespace std;

//Declare Variables
char squares[9];
int player;

//Define Functions
void NewGame();
void CreateBoard();
//void ContinueGame();
//void PlayGame();
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

	//Reset Square Array
	for (int sq = 0; sq < 9; sq++)
	{
		squares[sq] = (sq + 1);
	}

	//Create the Board
	CreateBoard();

	/PlayGame();
}

//Create Board
void CreateBoard()
{
	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[0] << "    |    " << squares[1] << "    |    " << squares[2] << "\n";
	cout << "\t   _________|_________|_________\n";
	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[4] << "    |    " << squares[5] << "    |    " << squares[6] << "\n";
	cout << "\t   _________|_________|_________\n";
	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[7] << "    |    " << squares[8] << "    |    " << squares[9] << "\n";
	cout << "\t\t    |         |\n";
}

//Play Game
void PlayGame()
{
	char mark;
	int won, choice;

	do {
		cout << "\n\nSelect a Square Number\n";
		cout << "Player %ds Turn:", player;
		cin >> choice;

		if (player == 1)
		{
			mark = 'X';
		}
		else
		{
			mark = 'O';
		}

#pragma region ChangeSquaresMark
		if (choice == 1 && squares[0] == '1')

			squares[0] = mark;
		else if (choice == 2 && squares[1] == '2')

			squares[1] = mark;
		else if (choice == 3 && squares[2] == '3')

			squares[2] = mark;
		else if (choice == 4 && squares[3] == '4')

			squares[3] = mark;
		else if (choice == 5 && squares[4] == '5')

			squares[4] = mark;
		else if (choice == 6 && squares[5] == '6')

			squares[5] = mark;
		else if (choice == 7 && squares[6] == '7')

			squares[6] = mark;
		else if (choice == 8 && squares[7] == '8')

			squares[7] = mark;
		else if (choice == 9 && squares[8] == '9')

			squares[8] = mark;
		else
		{
			printf("\n\n******Invalid Move*******\n");

			player--;
		}
#pragma endregion

		//Update Board
		CreateBoard();

		//Check if Game Won
		won = CheckWin();
	} while (won == -1);

	EndOfGame();
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