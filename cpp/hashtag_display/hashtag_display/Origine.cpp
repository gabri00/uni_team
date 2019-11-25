#include <iostream>

using namespace std;

int main()
{
	char hash = '#';
	int n, max_raw;

	cout << "Enter the number to display (only integers): ";
	cin >> n;

	if (n >= 1000)
	{
		cout << '\n';
		cout << " #   ###  ###  ###" << '\n';
		cout << "##   # #  # #  # #" << '\n';
		cout << " #   # #  # #  # #" << '\n';
		cout << " #   # #  # #  # #" << '\n';
		cout << "###  ###  ###  ###" << '\n';
		cout << '\n';

		return 0;
	}

	cout << "Enter the maximum amount per raw: ";
	cin >> max_raw;

	for (int y = 1; y < n+1; y++)
	{
		cout << hash << " ";

		if (y % max_raw == 0)	cout << '\n';

	}

	return 0;
}