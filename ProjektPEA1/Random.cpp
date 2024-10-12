#include<iostream>
#include <algorithm>
#include"Random.h"
#include<random>
using namespace std;

double Random::start()
{
	licznik.start();
	int licznik_losowan = 1000;
	int minimum = INT_MAX;
	auto rng = std::default_random_engine{};
	vector <int> kolejnosc;
	for (int i = 1; i < macierz.size(); i++)
	{
		kolejnosc.push_back(i);
	}
	while (licznik_losowan > 0)
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
			licznik_losowan = 1000;

		}
		else
		{
			licznik_losowan--;
		}

		shuffle(kolejnosc.begin(), kolejnosc.end(), rng);
	}
	waga_calkowita = minimum;
	cout << minimum << endl;
	return licznik.stop();
}
