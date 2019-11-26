#include <iostream>
#include <math.h>

using namespace std;

#define PI	3.14


int checkInput(int x)
{
	while (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Error, only numeric values are allowed, retry: ";
		cin >> dec >> x;
	}

	return x;
}

/*char checkSelection(char c)
{
	while (!cin)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Error, only letters are allowed, retry: ";
		cin >> c;
	}

	return c;
}*/


int main()
{
	float r;

	cout << "Before doing anything enter the length of the radius: ";
	cin >> dec >> r;

	r = checkInput(r);

	char sel;

	cout << "What do you want to calculate, area(a) or perimeter(p) or both(b)?";
	cin >> sel;

	//sel = checkSelection(sel);

	const float area = PI * pow(r, 2.0),
				per = 2 * PI * r;


	switch (sel)
	{
		case 'a':
			cout << "The area of the circle is: " << area << '\n';
			break;

		case 'p':
			cout << "The perimeter of the circle is: " << per << '\n';
			break;

		case 'b':
			cout << "The area is: " << area << " and the perimeter is: " << per << '\n';
			break;

		default:
			cout << sel << " is not a valid option you asshole\n";
			break;
	}


	char answer;

	cout << "\n\n";
	cout << "Would you like to calculate the area and perimeter of the inscribed square (y)/(n)? ";
	cin >> answer;

	//answer = checkSelection(answer);

	if (answer == 'n' || answer == 'N')		cout << "Okay, bye bitch.\n";
	else if (answer == 'y' || answer == 'Y')
	{
		cout << "Nice, I'll calculate them for you...\n";

		const float l = sqrt(pow(r, 2.0) + pow(r, 2.0)),
					sq_area = pow(l, 2.0),
					sq_per = l * 4;

		cout << "The area of the square is: " << sq_area << " and the perimeter: " << sq_per << '\n';
	}
	else	cout << answer << " is not valid expression!\n";

	return 0;
}