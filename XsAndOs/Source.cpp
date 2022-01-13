#include <iostream>
#include <fstream>

using namespace std;

//Declare Variables
char grid = 179;
char squares[9];
int player;

//Define Functions
void NewGame();
void CreateBoard();
void LoadGame();
void SaveGame();
void Menu(int player);

int main()
{
	int gameChoice;

	cout << "Please Enter 1 to Load a Saved Game or any Other Number to Start a New Game:\t";
	cin >> gameChoice;

	if (gameChoice == 1)
	{
		//Go to Load Game Function
		LoadGame();
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
	bool front = true;
	string message = "Welcome to Xs & Os";

	//Clear Console
	system("cls");//36

	cout << "\n\n\t";
	for (int i = message.length(); i < 36; i++)
	{
		if (front)
		{
			message = " " + message;
		}
		else
		{
			message = message + " ";
		}
		front = !front;
	}
	cout << message.c_str();
	cout << "\n\n\tPlayer 1: X\t\tPlayer 2: O\n\n";

	cout << "\t\t    " << grid << "         " << grid << endl;
	cout << "\t       " << squares[0] << "    " << grid << "    " << squares[1] << "    " << grid << "    " << squares[2] << endl;
	cout << "\t   _________" << grid << "_________" << grid << "_________" << endl;
	cout << "\t\t    " << grid << "         " << grid << endl;
	cout << "\t       " << squares[3] << "    " << grid << "    " << squares[4] << "    " << grid << "    " << squares[5] << endl;
	cout << "\t   _________" << grid << "_________" << grid << "_________" << endl;
	cout << "\t\t    " << grid << "         " << grid << endl;
	cout << "\t       " << squares[6] << "    " << grid << "    " << squares[7] << "    " << grid << "    " << squares[8] << endl;
	cout << "\t\t    " << grid << "         " << grid << endl;
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

//Check Square Choice
int CheckSquare(int choice, char mark)
{
	if (choice == 1 && squares[0] == '1')
	{
		squares[0] = mark;
		return 1;
	}

	else if (choice == 2 && squares[1] == '2')
	{
		squares[1] = mark;
		return 1;
	}

	else if (choice == 3 && squares[2] == '3')
	{
		squares[2] = mark;
		return 1;
	}

	else if (choice == 4 && squares[3] == '4')
	{
		squares[3] = mark;
		return 1;
	}

	else if (choice == 5 && squares[4] == '5')
	{
		squares[4] = mark;
		return 1;
	}

	else if (choice == 6 && squares[5] == '6')
	{
		squares[5] = mark;
		return 1;
	}

	else if (choice == 7 && squares[6] == '7')
	{
		squares[6] = mark;
		return 1;
	}

	else if (choice == 8 && squares[7] == '8')
	{
		squares[7] = mark;
		return 1;
	}

	else if (choice == 9 && squares[8] == '9')
	{
		squares[8] = mark;
		return 1;
	}

	else
	{
		return 0;
	}
}

//End of Game
void EndOfGame(int result, int winner)
{
	int choice;

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
	}

	cout << "\n\n0: New Game\tAnything else to Exit\nChoice:  ";
	cin >> choice;

	if (choice == 0)
	{
		NewGame();
	}
	else
	{
		exit(0);
	}
}

//Play Game
void PlayGame(int player)
{
	int won = -1, choice, error = 0, cont = 0;
	char mark;

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
			Menu(player);
		}

		else
		{
			error = CheckSquare(choice, mark);
		}

		//Error
		while (error == 0)
		{
			cerr << "******Invalid Move*******\nPlease Pick a Square Number: ";
			cin.ignore();
			cin >> choice;

			if (choice > 0 && choice < 10)
			{
				error = CheckSquare(choice, mark);
			}
		}
			
		//Update Board
		CreateBoard();

		//Check if Game Won
		won = CheckWin();

		//Update Player
		if (won == -1)
		{
			if (player == 1)
			{
				player++;
			}
			else
			{
				player--;
			}
		}
	} while (won == -1);

	EndOfGame(won, player);
}

//New Game
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

//Save Game
void SaveGame(int player)
{
	//Create Instance
	ofstream fileWrite;

	fileWrite.open("GameData.txt");

	for (int i = 0; i < 9; i++)
	{
		fileWrite << squares[i];
	}

	fileWrite << endl << player;

	fileWrite.close();
}

//Load Game
void LoadGame()
{
	//Create Instance
	ifstream fileRead;

	fileRead.open("GameData.txt");

	if (!fileRead)
	{
		cerr << "File couldnt be opened!!";
		CreateBoard();
		Menu(player);
	}

	for (int j = 0; j < 9; j++)
	{
		fileRead >> squares[j];
	}

	fileRead >> player;

	fileRead.close();

	PlayGame(player);
}

//Menu
void Menu(int player)
{
	int options, newG;

	cout << "\n\n" << "\t\t\t\t\t***** Menu *****" << endl;
	cout << "0: Continue Current Game\t1: New Game\t2: Save Game & Exit\t3: Load Game\t4: Exit\nPlease Choose an Option: ";
	cin >> options;

	switch (options)
	{
		case 0:
			CreateBoard();
			PlayGame(player);
		case 1:
			cout << "Are you sure you want to start a new game?\nEnter 1 for Yes or anything else for No:  ";
			cin >> newG;

			if (newG == 1)
			{
				NewGame();
			}
			else
				CreateBoard();
				Menu(player);
			break;
		case 2:
			SaveGame(player);
			exit(0);
			break;
		case 3:
			LoadGame();
			break;
		case 4:
			exit(0);
			break;
		default:
			CreateBoard();
			cerr << "Invalid Entry!!";
			Menu(player);
			break;
	}
}