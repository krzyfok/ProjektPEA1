#include<iostream>
#include"MainMenu.h"
#include"Bruteforce.h"
#include"NN.h"
#include"Random.h"
#include "MenuAbstr.h"
#include<fstream>
#include<string>
using namespace std;


void MainMenu:: wczytanie_konfiguracji()
{	//dodac parametry startowe - liczba powtórzen, rozmair macierzy, iteracje w random?
	string nazwa = "config.txt";
	ifstream plik(nazwa);

	if (plik.is_open()) {
		
		string aa;
		plik >> aa;
		cout << aa;
		plik >> aa;
		cout << aa;

		plik.close();
	}
	else {
		cout << "BRAK PLIKU\n";
	}
}
void MainMenu::main_menu() {
	wczytanie_konfiguracji();
	while (true)
	{
		printf("1.Wczytanie danych z pliku\n");
		printf("2.Wygenerowanie danych losowych\n");
		printf("3.Wyœwietlenie ostatnich danych\n");
		printf("4.Uruchomienie algorytmu\n");
		printf("5.Testowanie\n");
		printf("6.Wyjscie\n");


		int x;
		cin >> x;
		switch (x)
		{
		case 1:
			MenuAbstr::wczytywanie();
			break;
		case 2:
			MenuAbstr::generacja();
			break;
		case 3:
			MenuAbstr::wyswietlanie();
			break;
		case 4:
		{
			algorytmy_menu();
			break;
		}

		}
	}


}

void MainMenu:: algorytmy_menu()
{
	while (true)
	{
		printf("1.Przeglad zupelny\n");
		printf("2.Najblizszy sasiad\n");
		printf("3.Losowy\n");
		printf("4.Cofnij\n");


		int x;
		cin >> x;
		switch (x)
		{
		case 1:
		{
			Bruteforce b;
			cout<<"Czas: " << b.start() << endl;
			break;
		}
		case 2:
		{
			NN n;
			cout<<"Czas: " << n.start() << endl;
			break;
		}
		case 3:
		{
			Random r;
			cout << "Czas: " << r.start() << endl;
			break;
		}
		case 4:
			return;
		}
	}
}