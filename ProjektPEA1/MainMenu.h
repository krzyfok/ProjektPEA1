#include<vector>
using namespace std;
class MainMenu {
public:
	void main_menu();
	void algorytmy_menu();
	void wczytanie_konfiguracji();

	//zmienne konfiguracyjne
	static vector<int> rozmiary_macierzy;
	static int powtorzenia, liczba_instancji;
};