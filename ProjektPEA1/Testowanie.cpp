#include<iostream>
#include"Testowanie.h"
#include"MenuAbstr.h"
#include"Bruteforce.h"
#include"NN.h"
#include"Random.h"
#include<vector>
#include <iostream>
#include <fstream>

using namespace std;
void Testowanie:: test_start(vector <int> rozmiary, int powtorzenia, int progres,string plik_wyjsciowy)
{
	Bruteforce b;
	NN n;
	Random r;
	double czas=0;
	double suma=0;
	ofstream myfile;
	myfile.open(plik_wyjsciowy);
	if (!myfile.is_open()) {
		cout << "Nie udalo siê otworzyc pliku wyjsciowego!" << endl;
		return;
	}
	//brutefroce
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{
			system("cls");
			if(progres==1)cout << "Bruteforce " << instancje << "  " << i << endl;
			MenuAbstr ::generacja(rozmiary[instancje]);
			czas = b.start();
			myfile <<czas <<";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{
			system("cls");
			if (progres == 1)cout << "Bruteforce " << instancje << "  " << i << endl;
			MenuAbstr::generacja_sym(rozmiary[instancje]);
			czas = b.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}

	
	myfile << "\n";
	//NN
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if(progres==1)cout <<"NN " << instancje << "  " << i << endl;
			MenuAbstr::generacja(rozmiary[instancje]);
			czas = n.start();
			myfile << czas << ";";
			suma += czas;
			
		}
		myfile<<"srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";


	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if (progres == 1)cout << "NN " << instancje << "  " << i << endl;
			MenuAbstr::generacja_sym(rozmiary[instancje]);
			czas = n.start();
			myfile << czas << ";";
			suma += czas;

		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";

	//random
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if(progres==1)cout <<" Random " << instancje << " r " << i << endl;
			MenuAbstr::generacja(rozmiary[instancje]);
			czas = r.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile << "\n";
	for (int instancje = 0; instancje < rozmiary.size(); instancje++)
	{
		for (int i = 0; i < powtorzenia; i++)
		{

			system("cls");
			if (progres == 1)cout << " Random " << instancje << " r " << i << endl;
			MenuAbstr::generacja(rozmiary[instancje]);
			czas = r.start();
			myfile << czas << ";";
			suma += czas;
		}
		myfile << "srednia;" << (suma / powtorzenia);
		myfile << "\n";
		suma = 0;
	}
	myfile.close();
	cout << "koniec" << endl;
}