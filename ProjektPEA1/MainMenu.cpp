#include<iostream>
#include"MainMenu.h"
#include"Bruteforce.h"
#include"NN.h"
#include"Random.h"
#include "MenuAbstr.h"
#include"Testowanie.h"
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<int> MainMenu::rozmiary_macierzy;
int MainMenu:: powtorzenia;
int MainMenu::liczba_instancji;
int MainMenu::progres;
int MainMenu::tryb;
string MainMenu::dane_wejsciowe;
string MainMenu::dane_wyjsciowe;

void MainMenu:: wczytanie_konfiguracji()
{	//wczytywanie danych z pliku konfiguraycjnego
	string nazwa = "config.txt";
	ifstream plik(nazwa);
	
	if (plik.is_open()) {
		
		string nazwa;
		int dane;

		cout << "KONFIGURACJA: "<<endl;
		plik >> nazwa;
		plik >> tryb;
		cout << nazwa << " " << tryb << endl;

		plik >> nazwa;
		plik >> dane_wejsciowe;
		cout << nazwa << " " <<dane_wejsciowe << endl;

		plik >> nazwa;
		plik >> dane_wyjsciowe;
		cout << nazwa << " " << dane_wyjsciowe << endl;

		plik >> nazwa;
		plik >> progres;
		cout << nazwa << " " << progres << endl;


		plik >> nazwa ;
		plik >> liczba_instancji;
		cout << nazwa<<" " << liczba_instancji << endl;
		

		for (int i = 0; i < liczba_instancji; i++)
		{
			plik >> nazwa;
			plik >> dane;
			cout << nazwa<<" " << dane << endl;
			rozmiary_macierzy.push_back(dane);
		}

		plik >> nazwa;
		plik >> powtorzenia;
		cout << nazwa<<" " << powtorzenia << endl<<endl<<endl;

		plik.close();
		
	}
	else {
		cout << "BRAK PLIKU KONFIGURACYJNEGO\n";
		exit(0);
	}
}
void MainMenu::main_menu() {
	wczytanie_konfiguracji();

	if (tryb == 1)
	{
		Bruteforce b;
		NN n;
		Random r;

		MenuAbstr::wczytywanie(dane_wejsciowe);
		cout << "czas[ms]: " << b.start(); b.wyswietlanie_trasy();

		cout << "czas[ms]: " << n.start(); n.wyswietlanie_trasy();
		cout << "czas[ms]: " << r.start(); r.wyswietlanie_trasy();
		MenuAbstr::wyswietlanie();
		
	}
	else
	{

		Testowanie t;
		t.test_start(rozmiary_macierzy, powtorzenia, progres, dane_wyjsciowe);
	}

	cout<<"NACISNIJ DOWOLNY PRZYCISK BY ZAKONCZYC";
	getchar();

}

