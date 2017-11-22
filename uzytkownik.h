#include <iostream>
#include <string>

using namespace std;

class uzytkownik
{

public:

	string haslo;
	string login;

	uzytkownik();

	uzytkownik(string l);

	uzytkownik(string login, string haslo);

	void wyswietl();
	void pobierzdane();
};