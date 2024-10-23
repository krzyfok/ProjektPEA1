#include<iostream>
#include"Bruteforce.h"
using namespace std;

// Funkcja generuj�ca nast�pn� permutacj� leksykograficzn�  dla wektora kolejnosc
// Zwraca true, je�li uda�o si� wygenerowa� now� permutacj�, lub false, je�li obecna permutacja jest ostatnia

bool Bruteforce::nastepna_permutacja(vector<int>& kolejnosc)
{
	int n = kolejnosc.size(); // Rozmiar wektora

	// Znalezienie pierwszej pozycji j od ko�ca, gdzie kolejnosc[j] < kolejnosc[j+1]
	// Oznacza to  �e permutacja nie jest w porz�dku malej�cym
	int j = n - 2;
	while (j >= 0 && kolejnosc[j] >= kolejnosc[j + 1])
	{
		j--;
	}

	// Je�li nie znaleziono takiego j (j < 0), to obecna permutacja jest ostatnia (najwi�ksza leksykograficznie)
	if (j < 0) return false;

	// Znalezienie najwi�kszej pozycji k, dla kt�rej kolejnosc[k] > kolejnosc[j]
	// K oznacza minimalny element wi�kszy ni� kolejnosc[j]
	int k = n - 1;
	while (kolejnosc[k] <= kolejnosc[j])
	{
		k--;
	}

	// Zamiana warto�ci w pozycjach j i k, aby uzyska� wi�ksz� permutacj�
	swap(kolejnosc[j], kolejnosc[k]);

	// Odwr�cenie fragmentu tablicy za pozycj� j, aby uzyska� minimaln� permutacj� dla tej pozycji
	reverse(kolejnosc.begin() + j + 1, kolejnosc.end());

	// Zwracamy true, poniewa� uda�o si� wygenerowa� nast�pn� permutacj�
	return true;
}

double Bruteforce::start()
{
	double czas;
	int minimum = INT_MAX;
	vector<int> kolejnosc;
	//umieszczanie wierzcho�k�w w koljenosci rosn�cej w wektorze
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