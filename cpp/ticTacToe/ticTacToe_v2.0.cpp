#include <iostream>
//#include <limits>

using namespace std;

#define HEADER	"\t***\tTRIS GAME DEVELOPED BY LORENZO MONTANARO\t***\n"

char Tabella[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' },
player = 'X';


/*int checkCin(int a)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Input non valido, riprovare: ";
		cin >> a;
	}
}*/

void Disegno()
{
	cout << "\n\n\n";

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			cout << Tabella[row][col] << '\t';
		}
		cout << "\n\n\n";
	}
}

void Input()
{
	int a;

	cout << "E' il turno di " << player << ".\nInserire il numero della tabella da sostituire: ";
	cin >> a;

	//a = checkCin(a);

	switch (a)
	{
	case 1:
		if (Tabella[0][0] == '1')	Tabella[0][0] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 2:
		if (Tabella[0][1] == '2')	Tabella[0][1] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 3:
		if (Tabella[0][2] == '3')	Tabella[0][2] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 4:
		if (Tabella[1][0] == '4')	Tabella[1][0] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 5:
		if (Tabella[1][1] == '5')	Tabella[1][1] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 6:
		if (Tabella[1][2] == '6')	Tabella[1][2] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 7:
		if (Tabella[2][0] == '7')	Tabella[2][0] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 8:
		if (Tabella[2][1] == '8')	Tabella[2][1] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;

	case 9:
		if (Tabella[2][2] == '9')	Tabella[2][2] = player;
		else
		{
			cout << "Casella già occupata, riprova!\n";
			Input();
		}

		break;
	}
}

void SwitchPlayer()
{
	(player == 'X') ? player = 'O' : player = 'X';
}

char WinCheck()
{

	if (Tabella[0][0] == 'X' && Tabella[0][1] == 'X' && Tabella[0][2] == 'X')
		return 'X';
	else if (Tabella[1][0] == 'X' && Tabella[1][1] == 'X' && Tabella[1][2] == 'X')
		return 'X';
	else if (Tabella[2][0] == 'X' && Tabella[2][1] == 'X' && Tabella[2][2] == 'X')
		return 'X';

	else if (Tabella[0][0] == 'X' && Tabella[1][0] == 'X' && Tabella[2][0] == 'X')
		return 'X';
	else if (Tabella[0][1] == 'X' && Tabella[1][1] == 'X' && Tabella[2][1] == 'X')
		return 'X';
	else if (Tabella[0][2] == 'X' && Tabella[1][2] == 'X' && Tabella[2][2] == 'X')
		return 'X';

	else if (Tabella[0][0] == 'X' && Tabella[1][1] == 'X' && Tabella[2][2] == 'X')
		return 'X';
	else if (Tabella[2][0] == 'X' && Tabella[1][1] == 'X' && Tabella[0][2] == 'X')
		return 'X';


	else if (Tabella[0][0] == 'O' && Tabella[0][1] == 'O' && Tabella[0][2] == 'O')
		return 'O';
	else if (Tabella[1][0] == 'O' && Tabella[1][1] == 'O' && Tabella[1][2] == 'O')
		return 'O';
	else if (Tabella[2][0] == 'O' && Tabella[2][1] == 'O' && Tabella[2][2] == 'O')
		return 'O';

	else if (Tabella[0][0] == 'O' && Tabella[1][0] == 'O' && Tabella[2][0] == 'O')
		return 'O';
	else if (Tabella[0][1] == 'O' && Tabella[1][1] == 'O' && Tabella[2][1] == 'O')
		return 'O';
	else if (Tabella[0][2] == 'O' && Tabella[1][2] == 'O' && Tabella[2][2] == 'O')
		return 'O';

	else if (Tabella[0][0] == 'O' && Tabella[1][1] == 'O' && Tabella[2][2] == 'O')
		return 'O';
	else if (Tabella[2][0] == 'O' && Tabella[1][1] == 'O' && Tabella[0][2] == 'O')
		return 'O';

	return '/';
}

int main()
{
	cout << HEADER;
	int n = 0;

	Disegno();

	while (true)
	{
		n++;

		Input();

		Disegno();

		if (WinCheck() == 'X')
		{
			cout << "La X vince!\n";
			break;
		}
		else if (WinCheck() == 'O')
		{
			cout << "Il O vince!\n";
			break;
		}
		else if (WinCheck() == '/' && n == 9)
		{
			cout << "Pareggio!\n";
			break;
		}

		SwitchPlayer();
	}

	cout << "Partita terminata\n";

	return 0;
}
