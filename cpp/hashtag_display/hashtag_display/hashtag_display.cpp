#include <iostream>
#include <limits>
#include <random>

#define HASHTAG	'#'
#define HEADER	"*****\tWELCOME TO THE HASHTAG PARTY\t*****\n\n"

void print_hashtags(int n, int max_raw)
{
	int color = 0;

	for (int y = 1; y <= n; y++)
	{
		std::uniform_int_distribution<int> rand = std::uniform_int_distribution<int>(31, 36);
		std::mt19937 rng = std::mt19937(std::random_device{}());
		color = rand(rng);

		std::cout << "\033[0;" << color << "m" << HASHTAG << "\033[0m" << ' ';

		if (y % max_raw == 0)
			std::cout.put('\n');
	}
}

int main()
{
	using namespace std;

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
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> dec >> max_raw;
	}

	print_hashtags(n, max_raw);

	return 0;
}