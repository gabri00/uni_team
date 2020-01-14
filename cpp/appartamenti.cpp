// Si scriva un programma C++ che elabori le informazioni relative agli appartamenti in vendita presso un’agenzia immobiliare.
// Per ogni appartamento si dovranno memorizzare le seguenti informazioni:
// • codice identificativo(int);
// • indirizzo(due stringhe: via e comune);
// • numero di vani;
// • superficie in mq;
// • prezzo.
//
// Si supponga che il numero di appartamenti in vendita non superi le 100 unità. La collezione di appartamenti in vendita può essere realizzata come un array di appartamenti.
// Il programma dovrà fornire le seguenti funzionalità:
// • inserimento dei dati da parte dell’utente verificando la validità degli stessi (ovvero numero di vani, superficie e prezzo dovranno essere positivi);
// • calcolo e stampa a video del prezzo medio, minimo e massimo degli appartamenti in vendita;
// • calcolo e stampa a video del prezzo medio degli appartamenti con superficie compresa tra un valore minimo e un valore massimo inseriti dall’utente;
// • calcolo e stampa a video del numero di monolocali (n = 1), di bilocali(n = 2), di trilocali(n = 3), di appartamenti di 4, 5, 6, 7 e 8 vani e di quelli con più di 8 vani.
// • stampa a video delle informazioni relative a tutti gli appartamenti di n vani, con n inserito dall’utente;
// • stampa a video delle informazioni relative a tutti gli appartamenti il cui prezzo è compreso tra un valore minimo ed un valore massimo inseriti dall’utente.
// La main permetterà all’utente di selezionare una delle funzionalità fornite dal programma ed eseguire la funzione corrispondente.

#include <iostream>
#include <limits>

#define MAX_VANI	20
#define MAX_SUP		2000
#define MAX_PRICE	2000000

using namespace std;


struct address
{
	char via[20], comune[20];
};

struct apartment
{
	address add;
	int id, n_vani, sup, price;
};


void input_apartment(apartment a[], const int& n)
{
	cout << "\t--- Form inserimento specifiche dell'appartamento ---\n\n";

	cout << "codice identificativo: ";
	cin >> a[n].id;

	while (!cin || a[n].id < 0)
	{
		cout << "impossibile convalidare il codice identificativo, riprovare: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> a[n].id;
	}

	// comune e via non vengono verificati, implementazione in corso
	cout << "comune: ";
	cin >> a[n].add.comune;
	cout << "via/piazza: ";
	cin	>> a[n].add.via;

	cout << "numero di vani: ";
	cin >> a[n].n_vani;

	while (a[n].n_vani < 1 || a[n].n_vani > MAX_VANI || cin.fail())
	{
		cout << "numero di vani non valido, riprovare: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> a[n].n_vani;
	}

	cout << "superficie in mq: ";
	cin >> a[n].sup;

	while (a[n].sup < 1 || a[n].sup > MAX_SUP || cin.fail())
	{
		cout << "superficie non valida, reinserire il valore: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> a[n].sup;
	}

	cout << "prezzo: ";
	cin >> a[n].price;

	while (a[n].price < 1 || a[n].price > MAX_PRICE || cin.fail())
	{
		cout << "prezzo non valido, reinserire: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> a[n].price;
	}

	cout << '\n';
}

int avr_price(apartment a[], const int& n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
		sum += a[i].price;

	return sum / n;
}

void max_min_price(apartment a[], const int& n)
{
	int max = a[0].price,
		min = a[0].price;

	for (int i = 0; i < n; i++)
	{
		if (a[i].price > max)
			max = a[i].price;

		else if (a[i].price < min)
			min = a[i].price;
	}

	cout << "\nprezzo minimo: " << min << "\nprezzo massimo: " << max << "\n\n";
}

void avr_price_in_range(apartment a[], const int& n)
{
	int max, min,
		sum = 0,
		cnt = 0;

	cout << "Inserire la superficie minima: ";
	cin >> min;

	while (min < 1 || min >= MAX_SUP || cin.fail())
	{
		cout << "superficie non valida, reinserire il valore: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> min;
	}

	cout << "e quella massima: ";
	cin >> max;

	while (max <= min || max > MAX_SUP || cin.fail())
	{
		cout << "superficie non valida, reinserire il valore: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> max;
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i].sup >= min && a[i].sup <= max)
		{
			sum += a[i].price;
			cnt++;
		}
	}

	cout << "Prezzo medio degli appartamenti con supperficie compresa tra " << min << "mq e " << max << "mq: " << sum / cnt << "\n\n";
}

void vani(apartment a[], const int& n)
{
	int ap_vani[MAX_VANI + 1] = { 0 };

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= MAX_VANI; j++)
		{
			if (a[i].n_vani == j)
				ap_vani[j]++;
		}
	}

	for (int i = 1; i <= MAX_VANI; i++)
		cout << ap_vani[i] << " appartamenti con " << i << " vani\n";

	cout << '\n';
}

void info_n_vani(apartment a[], const int& cnt)
{
	int n;

	cout << "Inserire il numero di vani: ";
	cin >> n;

	while (n < 1 || n > MAX_VANI || cin.fail())
	{
		cout << "numero di vani invalido, riprovare: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> n;
	}

	cout << '\n';

	for (int i = 0; i < cnt; i++)
	{
		if (a[i].n_vani == n)
		{
			cout << "codice identificativo:  " << a[i].id << '\n';
			cout << "Comune:\t\t\t" << a[i].add.comune << '\n';
			cout << "Via:\t\t\t" << a[i].add.via << '\n';
			cout << "Superficie:\t\t" << a[i].sup << "mq\n";
			cout << "Prezzo:\t\t\t" << a[i].price << "$\n";
		}
		else
			cout << "Nessun appartamento appartiene al range specificato\n";
	}

	cout << '\n';
}

void info_price_range(apartment a[], const int& n)
{
	int min, max;

	cout << "Inserire il prezzo minimo: ";
	cin >> min;

	while (min < 1 || min >= MAX_PRICE || cin.fail())
	{
		cout << "prezzo non valido, reinserire: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> min;
	}

	cout << "e quello massimo: ";
	cin >> max;

	while (max <= min || max > MAX_PRICE || cin.fail())
	{
		cout << "prezzo non valido, reinserire: ";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> max;
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i].price >= min && a[i].price <= max)
		{
			cout << "codice identificativo:  " << a[i].id << '\n';
			cout << "Comune:\t\t\t" << a[i].add.comune << '\n';
			cout << "Via:\t\t\t" << a[i].add.via << '\n';
			cout << "Superficie:\t\t" << a[i].sup << "mq\n";
			cout << "Vani:\t\t\t" << a[i].n_vani << '\n';
			cout << "Prezzo:\t\t\t" << a[i].price << "$\n";
		}
		else
			cout << "Nessun appartamento appartiene al range specificato\n";
	}

	cout << '\n';
}

inline void esci(int& c)
{ c = 0; }

inline void err_case(int& choise)
{
	cout << choise << "Non corrisponde a nessuna funzione!";
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	choise = -1;
}

int main()
{
	apartment ap[100];

	int choise = -1,
		count = 0;

	while (choise != 0)
	{
		cout << "\t----------------------\n"
			 << "Scegli cosa fare:\n"
			 << "1. inserisci l'appartamento nel database\n"
			 << "2. prezzo medio, minimo e massimo degli appartamenti in vendita\n"
			 << "3. prezzo medio degli appartamenti con superficie compresa tra un valore minimo e un valore massimo\n"
			 << "4. visualizza quanti appartamenti hanno n vani\n"
			 << "5. info su appartamenti con n vani\n"
			 << "6. info di tutti gli appartamenti con prezzo compreso tra un minimo ed un massimo\n"
			 << "7. esci\n\n";

		cout << "Quale funzione eseguire? ";
		cin >> choise;
		cout << '\n';

		switch (choise)
		{
		case 1:
			input_apartment(ap, count);
			count++;
			break;

		case 2:
			cout << "La media del prezzo degli appartamenti in vendita e': " << avr_price(ap, count);
			max_min_price(ap, count);
			break;

		case 3:
			avr_price_in_range(ap, count);
			break;

		case 4:
			vani(ap, count);
			break;

		case 5:
			info_n_vani(ap, count);
			break;

		case 6:
			info_price_range(ap, count);
			break;

		case 7:
			esci(choise);
			break;

		default:
			err_case(choise);
			break;
		}
	}

	return 0;
}