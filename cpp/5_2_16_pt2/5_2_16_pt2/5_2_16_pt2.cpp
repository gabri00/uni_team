#include <iostream>

using namespace std;



int main()
{
	char a, c = 's';
	int count[3] = { 0 };

	while (c != 'n')
	{
		cin >> a;

		while (a < 'm' || a > 'o')
		{
			cout << "Errore\n";
			cin >> a;
		}

		if (a == 'm')		count[0]++;
		else if (a == 'n')	count[1]++;
		else if (a == 'o')	count[2]++;

		cout << "Continuare? ";
		cin >> c;
	}

	cout << "m: ";
	for (int i = 0; i < count[0]; i++)
		cout << '*';
	cout << '\n';

	cout << "n: ";
	for (int i = 0; i < count[1]; i++)
		cout << '*';
	cout << '\n';

	cout << "o: ";
	for (int i = 0; i < count[2]; i++)
		cout << '*';
	cout << '\n';

	return 0;
}