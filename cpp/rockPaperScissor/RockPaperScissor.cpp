#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits>

using namespace std;

inline void Intro()
{
    cout << "Welcome! Insert your name \n";
    getline(cin, PlayerName);
    cout << PlayerName << " it's a very nice name dude!\n";
    cout << "Let's start!\n";
}

void InputPlayer()
{
    cout << "Choose Rock, Paper o Scissor (R,P o S)\n";
    cin >> Player;

    Player = toupper(Player);

    while ((Player != 'R' && Player != 'P' && Player != 'S') || !cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << PlayerName << " are you doumb? Just choose R, P or S: ";
        cin >> Player;
    }
}

void InputComputer()
{
	srand(time(NULL));	//random seed
	Computer = rand() % 3;

	if		(Computer == 0)	Computer = 'R';
	else if (Computer == 1) Computer = 'P';
	else if (Computer == 2) Computer = 'S';
}

void WinCheck()
{
	//TIE
	if (Computer == Player)	cout << "TIE\n";
    
	/*if ((Computer == 'R') && (Player == 'R'))
        cout << "TIE\n";
    else if ((Computer == 'P') && (Player == 'P'))
        cout << "TIE\n";
    else if ((Computer == 'S') && (Player == 'S'))
        cout << "TIE\n";*/
    
	//WIN
	if		(Computer == 'R' && Player == 'P')	cout << PlayerName << " WIN\n";
	else if (Computer == 'R' && Player == 'S')	cout << "Computer WIN\n";

	else if (Computer == 'P' && Player == 'S')	cout << PlayerName << " WIN\n";
	else if (Computer == 'P' && Player == 'R')	cout << "Computer WIN\n";
    
	else if (Computer == 'S' && Player == 'R')	cout << PlayerName << " WIN\n";
	else if (Computer == 'S' && Player == 'P')	cout << "Computer WIN\n";
}

int main()
{
	string PlayerName;
	int Computer;
	char Player, stop;

	Intro();

	do
	{
		InputPlayer();
		InputComputer();
		WinCheck();

		cout << "If you want to continue digit yes(y): ";
		cin >> stop;

		if (cin.fail())
		{
			cout << "If you want to continue digit yes(y): ";
			cin.sync();
			cin.clear();
			cin >> stop;
		}

		stop = toupper(stop);
    } while(stop == 'Y');

	return 0;
}
