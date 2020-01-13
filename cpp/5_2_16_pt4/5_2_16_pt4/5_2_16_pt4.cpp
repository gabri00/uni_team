#include <iostream>

using namespace std;

bool contiene(char s[], char t[3])
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == t[0] && s[i + 1] == t[1] && s[i + 2] == t[2])
			return 1;
	}

	return 0;
}

int main()
{
	char str[64], p[] = "per";

	cout << "Stringa: ";
	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
	}

	if (contiene(str, p))
		cout << "Contenuto\n";
	else
		cout << "Non contenuto\n";

	return 0;
}