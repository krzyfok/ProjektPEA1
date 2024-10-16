#include<iostream>
#include <algorithm>
#include"Random.h"
#include<random>
using namespace std;

double Random::start()
{
	double czas;
	licznik.start();
		
	vector<bool> odwiedzone(macierz.size(),false);
	//losowanie 2 wierzcholków
	kolejnosc_przejscia.clear();
	int wierzcholek_1 = losowanie_wierzcholka(odwiedzone);
	odwiedzone[wierzcholek_1] = true;
	int wierzcholek_2 = losowanie_wierzcholka(odwiedzone);
	odwiedzone[wierzcholek_2] = true;
	//dodanie do sciezki
	kolejnosc_przejscia.push_back(wierzcholek_1);
	kolejnosc_przejscia.push_back(wierzcholek_2);

	for (int w = 0; w < macierz.size() - 2; w++)
	{
		//losowanie wierzcho³ka
		int losowany = losowanie_wierzcholka(odwiedzone);
		odwiedzone[losowany] = true;
	//szukanie najeloszego miejsca do wstawienia
		int pozycja = -1;
		int koszt = INT_MAX;
		//obliczanie najnizszego kosztu 
		for (int i = 0; i <kolejnosc_przejscia.size(); i++)
		{
			//uzwglednienie cyklu przy losowaniu skrajnego wierzcholka z sciezki
			int sprawdzany = (i + 1) % kolejnosc_przejscia.size();

			//int koszt_obecny = obliczanie_kosztu(kolejnosc_przejscia[i], losowany);
			int koszt_obecny = macierz[kolejnosc_przejscia[i]][losowany];
			if (koszt > koszt_obecny)
			{
				koszt = koszt_obecny;
				pozycja = i + 1;
			}

		}

		kolejnosc_przejscia.insert(kolejnosc_przejscia.begin() + pozycja, losowany);

	}
	czas = licznik.stop();

	waga_calkowita = 0;
	for (int i = 0; i < kolejnosc_przejscia.size() - 1; i++)
	{
		waga_calkowita += macierz[kolejnosc_przejscia[i]][kolejnosc_przejscia[i+1]];
	}
	waga_calkowita += macierz[kolejnosc_przejscia.back()][kolejnosc_przejscia[0]];
	cout <<"Random:              " << "waga: " << waga_calkowita << " ";
	return czas;
}

int Random::losowanie_wierzcholka(vector <bool> odwiedz)
{
	srand(time(0));
	int liczba_dostepnych=0;
	int indeks_wylosowany = 0;
	int indeks_dostepnych = 0;
	//liczenie liczby dostepnych wierzcholkow
	for (int i = 0; i < odwiedz.size(); i++)
	{
		if(odwiedz[i]==false)
		{
			liczba_dostepnych++;
		}
	}

	if (liczba_dostepnych == 0)
	{
		return -1;
	}
	indeks_wylosowany = rand() % (liczba_dostepnych);
	for (int i = 0; i < odwiedz.size(); i++)
	{
		if (odwiedz[i] == false)
		{
			if (indeks_wylosowany == indeks_dostepnych)
			{
				return i;
			}
			else
			{
				indeks_dostepnych++;
			}
		}
	}

}
