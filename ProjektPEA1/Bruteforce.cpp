#include<iostream>
#include <algorithm>
#include"Bruteforce.h"
using namespace std;
void Bruteforce::start()
{
	int minimum = INT_MAX;
	vector<int> kolejnosc;//wszytskie wierzcho³ki do permutacji
	for (int i = 1; i < macierz.size(); i++)
	{
		kolejnosc.push_back(i);
	}
//v1
/*	do
	{
		int koszt = 0;
		int wierzch_kolejny = 0;
		for (int i = 0; i < kolejnosc.size(); i++)
		{
			koszt += macierz[wierzch_kolejny][kolejnosc[i]];
			wierzch_kolejny = kolejnosc[i];
		}

		koszt+= macierz[wierzch_kolejny][0];
		if (koszt < minimum)minimum = koszt;
	}
	 while (next_permutation(kolejnosc.begin(), kolejnosc.end()));
	
		cout << minimum<<endl;

	*/

//v2

	kolejnosc_przejscia.clear();
	kolejnosc_przejscia.resize(macierz.size());
	while (next_permutation(kolejnosc.begin(), kolejnosc.end()))
	{
		int koszt = 0;
		int wierzch_kolejny = 0;
		
		kolejnosc_przejscia_nastepnego.clear();
		kolejnosc_przejscia_nastepnego.push_back(0);
		for (int i = 0; i < kolejnosc.size(); i++)
		{
			koszt += macierz[wierzch_kolejny][kolejnosc[i]];
			wierzch_kolejny = kolejnosc[i];
			kolejnosc_przejscia_nastepnego.push_back(wierzch_kolejny);
		}


		koszt += macierz[wierzch_kolejny][0];
		if (koszt < minimum)
		{
			
			minimum = koszt;
			
			kolejnosc_przejscia = kolejnosc_przejscia_nastepnego;

		}
		
	}
	waga_calkowita = minimum;
	cout << minimum << endl;
	
}