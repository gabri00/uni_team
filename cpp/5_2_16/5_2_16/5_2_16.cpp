#include <iostream>

using namespace std;

int divisibile(int n, const int d)
{
	int x = 0;

	while (n % d == 0)
	{
		n /= d;
		x++;
	}

	return x;
}

int main()
{
	int n, d;
	char c = 's';

	while (c != 'n')
	{
		cout << "Inserire i due numeri: ";
		cin >> n >> d;

		if (d < 1 || n < 0 || d > n)
		{
			cout << "errore\n";
			return -1;
		}

		cout << divisibile(n, d) << '\n' << "Continuare? ";

		cin >> c;
	}

	return 0;
}