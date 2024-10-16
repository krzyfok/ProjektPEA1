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
LicznikCzasu licznik;
void MenuAbstr::generacja(int n)
{

	int rozmiar=n;
	
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

}

void MenuAbstr::wyswietlanie_trasy()
{
	cout << "  TRASA: ";
	for (int i = 0; i < kolejnosc_przejscia.size(); i++)
	{
		cout << kolejnosc_przejscia[i] << " ";
	}
	cout << endl;

}

void MenuAbstr::wczytywanie(string nazwa)
{
	macierz.clear();
	
	int rozmiar;
	

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