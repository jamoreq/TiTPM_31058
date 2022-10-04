#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Podaj wyraz: ";
	cout << endl;
	string wyraz;
	while (getline(cin, wyraz))
	{
		for (int i = 0; i < wyraz.length(); i++)
		{
			if (wyraz[i] > 87)
			{
				if (wyraz[i] == 'X')
					wyraz[i] = 'A';
				if (wyraz[i] == 'Y')
					wyraz[i] = 'B';
				if (wyraz[i] == 'Z')
					wyraz[i] = 'C';
			}
			if (wyraz[i] > 87)
			{
				if (wyraz[i] == 'x')
					wyraz[i] = 'a';
				if (wyraz[i] == 'y')
					wyraz[i] = 'b';
				if (wyraz[i] == 'z')
					wyraz[i] = 'c';
			}
			if (wyraz[i] > 64)
			{
				wyraz[i] = wyraz[i] + 3;
			}
		}
		cout << endl;
		cout << "Szyfrowanie wyrazu..";
		cout << endl;
		for (int i = 0; i < wyraz.length(); i++)
		{
			cout << wyraz[i];
		}

		cout << '\n';
	}
	return 0;
}
