#include<iostream>
#include"Bruteforce.h"
using namespace std;

// Funkcja generuj¹ca nastêpn¹ permutacjê leksykograficzn¹  dla wektora kolejnosc
// Zwraca true, jeœli uda³o siê wygenerowaæ now¹ permutacjê, lub false, jeœli obecna permutacja jest ostatnia

bool Bruteforce::nastepna_permutacja(vector<int>& kolejnosc)
{
	int n = kolejnosc.size(); // Rozmiar wektora

	// Znalezienie pierwszej pozycji j od koñca, gdzie kolejnosc[j] < kolejnosc[j+1]
	// Oznacza to  ¿e permutacja nie jest w porz¹dku malej¹cym
	int j = n - 2;
	while (j >= 0 && kolejnosc[j] >= kolejnosc[j + 1])
	{
		j--;
	}

	// Jeœli nie znaleziono takiego j (j < 0), to obecna permutacja jest ostatnia (najwiêksza leksykograficznie)
	if (j < 0) return false;

	// Znalezienie najwiêkszej pozycji k, dla której kolejnosc[k] > kolejnosc[j]
	// K oznacza minimalny element wiêkszy ni¿ kolejnosc[j]
	int k = n - 1;
	while (kolejnosc[k] <= kolejnosc[j])
	{
		k--;
	}

	// Zamiana wartoœci w pozycjach j i k, aby uzyskaæ wiêksz¹ permutacjê
	swap(kolejnosc[j], kolejnosc[k]);

	// Odwrócenie fragmentu tablicy za pozycj¹ j, aby uzyskaæ minimaln¹ permutacjê dla tej pozycji
	reverse(kolejnosc.begin() + j + 1, kolejnosc.end());

	// Zwracamy true, poniewa¿ uda³o siê wygenerowaæ nastêpn¹ permutacjê
	return true;
}

double Bruteforce::start()
{
	double czas;
	int minimum = INT_MAX;
	vector<int> kolejnosc;
	//umieszczanie wierzcho³ków w koljenosci rosn¹cej w wektorze
	for (int i = 1; i < macierz.size(); i++)
	{
		kolejnosc.push_back(i);
	}


	kolejnosc_przejscia.clear();
	kolejnosc_przejscia.resize(macierz.size());
	licznik.start();
	do
	{
		int koszt = 0;
		int wierzch_kolejny = 0;
		//liczenie kosztu dla permutacji
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
		//wytwarzanie kolejnej permutacji
	} while (nastepna_permutacja(kolejnosc));

	czas = licznik.stop();
	waga_calkowita = minimum;
	cout<<"Bruteforce:          " << "waga: " << minimum << " ";
	return czas;
	
}