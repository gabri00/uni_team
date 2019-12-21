#include <iostream>
#include <random>
#include <string>

#define HEADER	"Gioco della roulette sviluppato in C++ tanto perche' non avevo un cazzo da fare\n"

std::string line(60, '-');

int main()
{
	using namespace std;

	#ifndef HEADER
	#define HEADER
	#endif

	cout << HEADER << line << '\n';

	int capitale = 100,	//parte da 100
		puntata = 1,	// > 0
		scommesso,		// da 0 a 36
		uscito;			// da 0 a 36

	cout << "Benvenuto alla roulette, il tuo capitale iniziale e' " << capitale << "$\n";

	while (puntata > 0)
	{
		cout << "Quanto denaro si desidera puntare (inserisci un numero negativo o una lettera per abbandonare): ";
		cin >> puntata;

		while (capitale - puntata < 0)
		{
			cin.sync();
			cin.clear();
			cout << "Non puoi puntare più del tuo capitale attuale, inserire una puntata valida: ";
			cin >> puntata;
		}

		capitale -= puntata;

		cout << "Per scommettere inserire un numero da 0 a 36: ";
		cin >> scommesso;

		while (scommesso < 0 || scommesso > 36)
		{
			cout << "Il numero che ha inserito non era corretto, inserire solo numeri tra 0 e 36: ";
			cin >> scommesso;
		}

		auto rand = std::uniform_int_distribution<int>(1, 36);
		std::mt19937 rng = std::mt19937(std::random_device{}());
		uscito = rand(rng);

		cout << "uscito il numero " << uscito << '\n';

		if (scommesso == uscito)
		{
			capitale += puntata * 2;
			cout << "Hai vinto, nice job!\n";
		}
		else	cout << "\033[0;31mHai perso lezzino, ritenta!\033[0m\n";

		cout << "Il tuo capitale e' ora di: " << capitale << "$\n";

		if (capitale <= 0)
		{
			cout << "Hai finito i soldi pooovero, bye bye\n";
			puntata = -1;
		}
		else	cout << "Punta ancora!\n";
	}

	return 0;
}