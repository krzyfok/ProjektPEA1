#include<iostream>
#include <algorithm>
#include"NN.h"
using namespace std;
//http://algorytmy.ency.pl/artykul/algorytm_najblizszego_sasiada
//http://algorytmy.ency.pl/artykul/powtarzalny_algorytm_najblizszego_sasiada
//https://kcir.pwr.edu.pl/~witold/aiarr/2006_projekty/TSP/
//NN RNN?
double NN::start()
{
	double czas;
	kolejnosc_przejscia.clear();
	licznik.start();
	

	int waga = 0;
	int start = rand() % macierz.size();
	int aktualny = start;
	vector<int> odwiedzone(macierz.size(), 0);
	odwiedzone[aktualny] = 1;
	//szukanie minimum po³¹czonego
	int laczone_minimum = INT_MAX;
	int nowy = -1;
	kolejnosc_przejscia_nastepnego.clear();
	kolejnosc_przejscia_nastepnego.push_back(aktualny);
	for (int k = 0; k < macierz.size() - 1; k++) {
		laczone_minimum = INT_MAX;
		nowy = -1;
		for (int i = 0; i < macierz.size(); i++)
		{

			if (odwiedzone[i] == 0 && laczone_minimum > macierz[aktualny][i])
			{
				laczone_minimum = macierz[aktualny][i];
				nowy = i;

			}

		}
		if (nowy != -1) {
			waga += laczone_minimum;
			aktualny = nowy;
			kolejnosc_przejscia_nastepnego.push_back(aktualny);
			odwiedzone[aktualny] = 1;
		}
	}
	waga += macierz[aktualny][start];



	czas = licznik.stop();
	kolejnosc_przejscia.clear();
	kolejnosc_przejscia = kolejnosc_przejscia_nastepnego;
	cout<<"Nearest Neighbour:   " << "waga: " << waga << " ";
	waga_calkowita = waga;
	return czas;
}
