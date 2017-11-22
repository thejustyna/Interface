#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "uzytkownik.h"
#include "OpcjaMenu.h"

using namespace std;


class baza
{
public:
	vector<uzytkownik> ksiazka;
	vector<OpcjaMenu> opcje;
	uzytkownik* zalogowany;

	baza();

	void wyswietl_opcje();
	void aktywuj_opcje(char wybor);
	void dezaktywuj_opcje(char wybor);
	bool wybor_prawidlowy(char wybor);
	void dodaj_uzytkownika();
	void wyswietl_uzytkownikow();
	void wczytaj_uzytkownikow();
	void logowanie();
	void wyloguj();
	void wyjscie();

	uzytkownik* znajdz(string login);

	void interfejs();

	void czat();
};
