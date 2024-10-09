#ifndef MENUABSTR_H
#define MENUABSTR_H

#include <iostream>
#include <vector>
using namespace std;

class MenuAbstr {
public:
    static vector<vector<int>> macierz;
    static vector<int> kolejnosc_przejscia;
    static vector<int> kolejnosc_przejscia_nastepnego;
    static int waga_calkowita;
    static void generacja();
    static void wyswietlanie();
    static void wczytywanie();

    virtual void start() = 0; 
};

#endif
