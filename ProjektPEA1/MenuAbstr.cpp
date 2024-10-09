#include"MenuAbstr.h"
#include<iostream>
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
vector<vector<int>> MenuAbstr::macierz;
vector<int> MenuAbstr::kolejnosc_przejscia;
vector<int> MenuAbstr::kolejnosc_przejscia_nastepnego;
int MenuAbstr::waga_calkowita =0;
void MenuAbstr::generacja()
{

	int rozmiar;
	cout << "podaj ilosc miast: ";
	cin >> rozmiar;
	
	//deklaracja rozmiary wektora
	macierz.resize(rozmiar);
	
	for (int i = 0; i < rozmiar; i++)
	{
		macierz[i].resize(rozmiar);
	}
	//genracja
	for (int i = 0; i < rozmiar; i++)
	{
		
		for (int k = 0; k < rozmiar; k++)
		{
			if (k != i)
			{
				do
				{
					macierz[i][k] = rand();

				} while (macierz[i][k]==macierz[k][i]);
			}
			else
			{
				macierz[i][k] = -1;
			}
		}
	}



}

void MenuAbstr :: wyswietlanie()
{
	for (int i = 0; i < macierz.size(); i++)
	{
		for (int k = 0; k < macierz[i].size(); k++)
		{
			cout << macierz[i][k] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < kolejnosc_przejscia.size(); i++)
	{
		cout << kolejnosc_przejscia[i] << " ";
	}
	cout << endl;
	cout << "WAGA: " << " " << waga_calkowita << endl;
}

void MenuAbstr::wczytywanie()
{
	macierz.clear();
	string nazwa;
	int rozmiar;
	cout << "PODAJ NAZWE PLIKU: ";
	cin >> nazwa;

	ifstream plik(nazwa);  

	if (plik.is_open()) {
		plik >> rozmiar;  

		macierz.resize(rozmiar, vector<int>(rozmiar));

		for (int i = 0; i < rozmiar; i++) {
			for (int j = 0; j < rozmiar; j++) {
				plik >> macierz[i][j]; 
			}
		}

		plik.close();  
	}
	else {
		cout << "BRAK PLIKU\n";  
	}
}