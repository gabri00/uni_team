#include <iostream>
#include <iomanip>

using namespace std;

#define HASHTAG	'#'

int main()
{
	int n, max_raw;

	cout << "Enter the number to display (only integers): ";
	cin >> dec >> n;

	if (cin.fail())
	{
		cout << "errore, sono consentiti solo valori numerici\n";
		return -1;
	}



	if (n >= 1000)
	{
		cout << '\n';
		cout << " #   ###   ###   ###" << '\n';
		cout << "##   # #   # #   # #" << '\n';
		cout << " #   # #   # #   # #" << '\n';
		cout << " #   # #   # #   # #" << '\n';
		cout << "###  ###   ###   ###" << '\n';
		cout << '\n';
		return 0;
	}

	cout << "Enter the maximum amount per raw: ";
	cin >> dec >> max_raw;

	while (max_raw == 0)
	{
		cout << "at least one element per raw, enter a valid number: ";
		cin.sync();
		cin.clear();
		cin >> dec >> max_raw;
	}

	for (int y = 1; y < n + 1; y++)
	{
		cout << HASHTAG << ' ';

		if (y % max_raw == 0)	cout.put('\n');

	}

	return 0;
}