#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	
	string wiadomosc, wiadomosc_temp;
	cout << "Podaj ciag znakow do zakodowania: ";
	cin >> wiadomosc;
	cout<<endl;
	wiadomosc_temp = wiadomosc;
	sort(wiadomosc_temp.begin(), wiadomosc_temp.end());
	
	char temp = wiadomosc_temp[0];
	int licznik = 1;

	vector<int> ile; vector<char> kolej;

	for (int i = 1; i < wiadomosc_temp.length(); i++){
	 if (temp == wiadomosc_temp[i]) licznik++;
	  if (temp != wiadomosc_temp[i]) 
		{
		 kolej.push_back(temp);
		 ile.push_back(licznik);
		 for (int j = ile.size() - 1; j > 0; j--)
		{
		 if(ile[j] > ile[j - 1]) 
		 swap(ile[j], ile[j - 1]), 
		 swap(kolej[j], kolej[j - 1]);
		}
		 licznik = 1;
		 temp = wiadomosc_temp[i];
		}
		 if (temp == wiadomosc_temp[i] && i == wiadomosc_temp.length() - 1)
		{
		 kolej.push_back(temp);
		 ile.push_back(licznik);
		}
	}
	 wiadomosc_temp.empty(),
	 wiadomosc_temp.erase();
	
	for (int i = 0; i < kolej.size(); i++)
	cout << kolej[i] << ": " << ile[i] << endl;
}
