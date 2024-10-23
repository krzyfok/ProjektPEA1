#include<iostream>
#include <algorithm>
#include"NN.h"
using namespace std;


int NN :: rNN(int w)
{

	int waga = 0;
	int start = w;
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
			//szukanie najbl¿szego wierzcho³ka
			if (odwiedzone[i] == 0 && laczone_minimum > macierz[aktualny][i])
			{
				laczone_minimum = macierz[aktualny][i];
				nowy = i;

			}

		}//dodawanie najbli¿szego do drogi
		if (nowy != -1) {
			waga += laczone_minimum;
			aktualny = nowy;
			kolejnosc_przejscia_nastepnego.push_back(aktualny);
			odwiedzone[aktualny] = 1;
		}
	}
	waga += macierz[aktualny][start];



	
	return waga;


}
double NN::start()
{
	
	double czas;
	int waga_tymczasowa = INT_MAX;
	waga_calkowita = INT_MAX;
	kolejnosc_przejscia.clear();
	licznik.start();
	for (int i = 0; i < macierz.size(); i++)
	{
		waga_tymczasowa = NN::rNN(i);
		if (waga_tymczasowa < waga_calkowita)
		{
			waga_calkowita = waga_tymczasowa;
			kolejnosc_przejscia.clear();
			kolejnosc_przejscia = kolejnosc_przejscia_nastepnego;
		}
	}

	czas = licznik.stop();
	cout << "Nearest Neighbour:   " << "waga: " << waga_calkowita << " ";
	
	return czas;



}
