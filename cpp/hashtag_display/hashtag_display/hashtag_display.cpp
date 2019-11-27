#include <iostream>
#include <limits>

using namespace std;

#define HASHTAG	'#'
#define HEADER	"*****\tWELCOME TO THE HASHTAG PARTY\t*****\n\n"


int main()
{
	cout << HEADER;

	int n, max_raw;

	cout << "Enter the number to display (only integers): ";
	cin >> dec >> n;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Error, only numeric values are allowed, retry: ";
		cin >> dec >> n;
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

	cout << "Enter the maximum amount of '#' per raw: ";
	cin >> dec >> max_raw;

	while (max_raw == 0)
	{
		cout << "at least one element per raw, enter a valid number: ";
		cin.sync();
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> dec >> max_raw;
	}

	for (int y = 1; y < n + 1; y++)
	{
		cout << HASHTAG << ' ';

		if (y % max_raw == 0)	cout.put('\n');

	}

	return 0;
}