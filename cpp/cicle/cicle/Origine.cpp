#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	float r;
	const float PI = 3.14f;
	char sel;

	cout << "Before doing anything enter the length of the radius: ";
	cin >> r;

	cout << "What do you want to calculate, area(a) or perimeter(p) or both(b)?";
	cin >> sel;

	float area = PI * pow(r, 2.0);
	float per = 2 * PI * r;

	if (sel == 'a')
		cout << "The area of the circle is: " << area << endl;
	else if (sel == 'p')
		cout << "The perimeter of the circle is: " << per << endl;
	else if (sel == 'b')
		cout << "The area is: " << area << " and the perimeter is: " << per << endl;
	else
		cout << sel << " is not a valid option you asshole" << endl;


	char answer;

	cout << "\n\n";
	cout << "Would you like to calculate the area and perimeter of the inscribed square (y)/(n)? ";
	cin >> answer;

	if (answer == 'n' || answer == 'N')		cout << "Okay, bye bitch." << endl;
	else if (answer == 'y' || answer == 'Y')
	{
		cout << "Nice, I'll calculate them for you..." << endl;

		float l = sqrt(pow(r, 2.0) + pow(r, 2.0));
		float sq_area = pow(l, 2.0);
		float sq_per = l * 4;

		cout << "The area of the square is: " << sq_area << " and the perimeter: " << sq_per << endl;
	}


	return 0;
}