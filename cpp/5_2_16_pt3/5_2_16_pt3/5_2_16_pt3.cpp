#include <iostream>

using namespace std;

#define N_SPETTACOLI	6

struct Biglietti
{
	double p_platea, p_galleria;
	int n_platea[N_SPETTACOLI],
		n_galleria[N_SPETTACOLI];
};


int main()
{
	Biglietti b;
	
	do
	{
		cout << "Inserire il prezzo dei biglietti in platea e poi in galleria: ";
		cin >> b.p_platea >> b.p_galleria;

		if (b.p_platea < 1 || b.p_galleria < 1)
			cout << "Errore\n";

	} while (b.p_platea < 1 || b.p_galleria < 1);

	for (int i = 0; i < N_SPETTACOLI; i++)
	{
		do
		{
			cout << "Inserire il numero dei biglietti in platea e poi in galleria: ";
			cin >> b.n_platea[i] >> b.n_galleria[i];

			if (b.n_platea[i] < 0 || b.n_galleria[i] < 0)
				cout << "Errore\n";
		} while (b.n_platea[i] < 0 || b.n_galleria[i] < 0);
	}
	
	int sum_p = 0,
		sum_g = 0,
		avr = 0,
		sum_p = 0;

	for (int i = 0; i < N_SPETTACOLI; i++)
	{
		sum_p += b.n_platea[i];
		sum_g += b.n_galleria[i];
	}

	cout << "Biglietti in platea totali: " << sum_p << '\n';
	cout << "Biglietti in galleria totali: " << sum_g << '\n';

	avr = (sum_p + sum_g) / (N_SPETTACOLI*2);

	cout << "Media dei biglietti venduti: " << avr << '\n';

	cout << "Ricavo complessivo: " << b.p_platea * 6 + b.p_galleria * 6 << '\n';

	int max = b.n_galleria[0] + b.n_platea[0],
		min = b.n_galleria[0] + b.n_platea[0];

	for (int i = 0; i < N_SPETTACOLI; i++)
	{
		int now = b.n_galleria[i] + b.n_platea[i],
			after = b.n_galleria[i + 1] + b.n_platea[i + 1];
	
		if (now > after)	max = now;
		if (now < after)	min = now;
	}

	cout << "Numero massimo di biglietti venduti: " << max << '\n';
	cout << "Numero minimo di biglietti venduti: " << min << '\n';

	return 0;
}