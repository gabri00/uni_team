#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int capitale = 100;
	int puntata = 1;	// > 0
	int scommesso;	//da 0 a 36
	int uscito;		//da 0 a 36

	cout << "Benvenuto alla roulette, il tuo capitale iniziale è " << capitale << "$" << endl;

	while (puntata > 0)
	{
		cout << "Quanto denaro si desidera puntare (inserisci un numero negativo per abbandonare): ";
		cin >> puntata;

		capitale -= puntata;

		cout << "Per scommettere inserire un numero da 0 a 36: ";
		cin >> scommesso;

		while (scommesso < 0 || scommesso > 36)
		{
			cout << "Il numero che ha inserito non era corretto, inserire solo numeri tra 0 e 36: ";
			cin >> scommesso;
		}

		uscito = rand() / 37;

		cout << "uscito il numero " << uscito << endl;

		if (scommesso == uscito)
		{
			capitale += puntata * 2;
			cout << "Hai vinto, nice job!" << endl;
		}
		else	cout << "Hai perso lezzino, ritenta!" << endl;

		cout << "Il tuo capitale è ora di: " << capitale << "$" << endl;

		if (capitale <= 0)
		{
			cout << "Hai finito i soldi pooovero, bye bye" << endl;
			puntata = -1;
		}
		else	cout << "Punta ancora!" << endl;
	}
}