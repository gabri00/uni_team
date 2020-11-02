#include <iostream>
#include <string.h>

using namespace std;

static int converti(int b[], const int n)
{
	int dec = 0;

	for (short i = 0; i < n; i++)
		dec = dec * 2 + b[i];

	return dec;
}

int main()
{
	const int byte_size = 8;

	char str[byte_size + 1];
	int num[byte_size] = { 0 };
	bool flag;

	do
	{
		flag = false;

		cout << "Inserire un byte: ";
		cin >> str;

		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '0' || str[i] == '1')
				num[i] = str[i] - '0';
			else
			{
				cout << "Errore, il bit non e' valido\n";
				flag = true;
				break;
			}
		}

		if (strlen(str) < byte_size && !flag)
		{
			cout << "Errore, lungezza del byte incorretta\n";
			flag = true;
		}
	} while (flag);

    cout << converti(num, byte_size);

	return 0;
}