#include "tic_tac_toe.h"
#include <iostream>

using namespace std;

Tris::Tris()
{
	cout << HEADER;
}

Tris::~Tris()
{
	cout << "Partita terminata\n";
}

void Tris::Draw()
{
	cout << "\n\n\n";

	for (short row = 0; row < GRID; row++)
	{
		for (short col = 0; col < GRID; col++)
			cout << table[row][col] << '\t';

		cout << "\n\n\n";
	}
}

void Tris::Input(char player)
{
	int a;

	cout << "E' il turno di " << player << ".\nInserire il numero della table da sostituire: ";
	cin >> a;

	switch (a)
	{
	case 1:
		checkTable(0, 0, '1');
		break;

	case 2:
		checkTable(0, 1, '2');
		break;

	case 3:
		checkTable(0, 2, '3');
		break;

	case 4:
		checkTable(1, 0, '4');
		break;

	case 5:
		checkTable(1, 1, '5');
		break;

	case 6:
		checkTable(1, 2, '6');
		break;

	case 7:
		checkTable(2, 0, '7');
		break;

	case 8:
		checkTable(2, 1, '8');
		break;

	case 9:
		checkTable(2, 2, '9');
		break;
	}
}

void Tris::checkTable(int x, int y, char a)
{
	if (table[x][y] == a)	table[x][y] = player;
	else
	{
		cout << "Casella già occupata, riprova!\n";
		Input(player);
	}
}

inline void Tris::SwitchPlayer(char& player)
{
	(player == 'X') ? player = 'O' : player = 'X';
}

const char Tris::WinCheck()
{
	for (short x = 0; x < GRID; x++)
	{
		if (table[x][0] == 'X' && table[x][1] == 'X' && table[x][2] == 'X')
			return 'X';
	}

	for (short y = 0; y < GRID; y++)
	{
		if (table[0][y] == 'X' && table[1][y] == 'X' && table[2][y] == 'X')
			return 'X';
	}

	if (table[0][0] == 'X' && table[1][1] == 'X' && table[2][2] == 'X')
		return 'X';
	else if (table[2][0] == 'X' && table[1][1] == 'X' && table[0][2] == 'X')
		return 'X';

	for (short x = 0; x < GRID; x++)
	{
		if (table[x][0] == 'O' && table[x][1] == 'O' && table[x][2] == 'O')
			return 'O';
	}

	for (short y = 0; y < GRID; y++)
	{
		if (table[0][y] == 'O' && table[1][y] == 'O' && table[2][y] == 'O')
			return 'O';
	}

	if (table[0][0] == 'O' && table[1][1] == 'O' && table[2][2] == 'O')
		return 'O';
	else if (table[2][0] == 'O' && table[1][1] == 'O' && table[0][2] == 'O')
		return 'O';

	return '/';
}


int main()
{
	int n(0);
	Tris tris;

	tris.Draw();

	while (true)
	{
		n++;

		tris.Input(tris.getPlayer());

		tris.Draw();

		if (tris.WinCheck() == 'X')
		{
			cout << "La X vince!\n";
			break;
		}
		else if (tris.WinCheck() == 'O')
		{
			cout << "Il O vince!\n";
			break;
		}
		else if (tris.WinCheck() == '/' && n == 9)
		{
			cout << "Pareggio!\n";
			break;
		}

		tris.SwitchPlayer(tris.getPlayerRef());
	}

	return 0;
}
