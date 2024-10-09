#include<iostream>
#include"MainMenu.h"
#include"Bruteforce.h"
#include"NN.h"
#include "MenuAbstr.h"

using namespace std;
void MainMenu::main_menu() {
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
			b.start();
			break;
		}
		case 2:
		{
			NN n;
			n.start();
			break;
		}
		case 4:
			return;
		}
	}
}