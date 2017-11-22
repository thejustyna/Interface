#include "uzytkownik.h"
using namespace std;


uzytkownik::uzytkownik()
{
}

uzytkownik::uzytkownik(string l) :
	login{l}
{
}

uzytkownik::uzytkownik(string login, string haslo) :
	login{login}, haslo{haslo}
{
}

void uzytkownik::wyswietl()
{
	cout<<login<<endl;
}

void uzytkownik::pobierzdane()
{
	cout<<"Podaj login\n";
	cin>>login;
	cout<<"Podaj haslo\n";
	cin>>haslo;
}
