#include <iostream>

using namespace std;

//Declare Variables
char squares[9];
int player;

//Define Functions
void NewGame();
void CreateBoard();
//void ContinueGame();
//void SaveGame();
void EndOfGame();
void Menu();

int main()
{
	int gameChoice;

	cout << "Please Enter 1 to Load a Saved Game or any Other Number to Start a New Game:\t";
	cin >> gameChoice;

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

	return 0;
}

//Create Board
void CreateBoard()
{
	//Clear Console
	system("cls");

	cout << "\n\t\t Welcome to Xs & Os\n\n";
	cout << "\tPlayer 1: X\t\tPlayer 2: O\n\n";

	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[0] << "    |    " << squares[1] << "    |    " << squares[2] << "\n";
	cout << "\t   _________|_________|_________\n";
	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[3] << "    |    " << squares[4] << "    |    " << squares[5] << "\n";
	cout << "\t   _________|_________|_________\n";
	cout << "\t\t    |         |\n";
	cout << "\t       " << squares[6] << "    |    " << squares[7] << "    |    " << squares[8] << "\n";
	cout << "\t\t    |         |\n";
}

//Check for Win
int CheckWin()
{
	//Horizontal
	if (squares[0] == squares[1] && squares[1] == squares[2])
	{
		return 1;
	}

	else if (squares[3] == squares[4] && squares[4] == squares[5])
	{
		return 1;
	}

	else if (squares[6] == squares[7] && squares[7] == squares[8])
	{
		return 1;
	}

	else if (squares[0] == squares[3] && squares[3] == squares[6])
	{
		return 1;
	}

	else if (squares[1] == squares[4] && squares[4] == squares[7])
	{
		return 1;
	}

	else if (squares[2] == squares[5] && squares[5] == squares[8])
	{
		return 1;
	}

	else if (squares[0] == squares[4] && squares[4] == squares[8])
	{
		return 1;
	}

	else if (squares[2] == squares[4] && squares[4] == squares[6])
	{
		return 1;
	}

	else if (squares[0] != '1' && squares[1] != '2' && squares[2] != '3'
		&& squares[3] != '4' && squares[4] != '5' && squares[5] != '6'
		&& squares[6] != '7' && squares[7] != '8' && squares[8] != '9')

		return 0;
	else
		return -1;
}


//End of Game
void EndOfGame(int result, int winner)
{
	cout << "\n\n****Game Over***\n";

	//Winner
	if (result == 1)
	{
		cout << "Congratulations to player " << winner << ", this games winner!!!";
	}

	//No Winner
	else
	{
		cout << "Game has ended in a draw";
		Menu();
	}
}

//Play Game
void PlayGame(int player)
{
	char mark;
	int won = -1, choice, error = 0;

	//Update Board
	CreateBoard();

	do {
		cout << "\n\nSelect a Square Number or 0 for Menu\n";
		cout << "Player " << player << "s Turn: ";
		cin >> choice;

		if (player == 1)
		{
			mark = 'X';
		}
		else
		{
			mark = 'O';
		}

		if (choice == 0)
		{
			Menu();
		}

#pragma region ChangeSquaresMark
		if (choice == 1 && squares[0] == '1')
		{
			squares[0] = mark;
		}

		else if (choice == 2 && squares[1] == '2')
		{
			squares[1] = mark;
		}

		else if (choice == 3 && squares[2] == '3')
		{
			squares[2] = mark;
		}

		else if (choice == 4 && squares[3] == '4')
		{
			squares[3] = mark;
		}

		else if (choice == 5 && squares[4] == '5')
		{
			squares[4] = mark;
		}

		else if (choice == 6 && squares[5] == '6')
		{
			squares[5] = mark;
		}

		else if (choice == 7 && squares[6] == '7')
		{
			squares[6] = mark;
		}

		else if (choice == 8 && squares[7] == '8')
		{
			squares[7] = mark;
		}

		else if (choice == 9 && squares[8] == '9')
		{
			squares[8] = mark;
		}
		else
		{
			error = 1;
		}
#pragma endregion

		//Error
		while(error == 1)
		{
			cerr << "******Invalid Move*******\nPlease Pick a Square Number: ";
			cin.ignore();
			cin >> choice;
			error = 0;
		}
		
		//Update Board
		CreateBoard();

		//Check if Game Won
		won = CheckWin();

		//Update Player
		if (player == 1)
		{
			player++;
		}
		else
		{
			player--;
		}
	} while (won == -1);

	EndOfGame(won, player);
}

//NewGame
void NewGame()
{
	//Declare Variables
	int player = 1;

	//Reset Square Arrays
	for (int sq = 0; sq < 9; sq++)
	{
		//Square Char
		switch (sq)
		{
		case 0:
			squares[0] = '1';
			break;
		case 1:
			squares[1] = '2';
			break;
		case 2:
			squares[2] = '3';
			break;
		case 3:
			squares[3] = '4';
			break;
		case 4:
			squares[4] = '5';
			break;
		case 5:
			squares[5] = '6';
			break;
		case 6:
			squares[6] = '7';
			break;
		case 7:
			squares[7] = '8';
			break;
		case 8:
			squares[8] = '9';
			break;
		default:
			break;
		}
	}

	//Create the Board
	CreateBoard();

	PlayGame(player);
}

void Menu()
{

}