#include <iostream>
#include<windows.h>
#include "baza.h"


using namespace std;

baza::baza():
    opcje
{
    {'d',"dodaj",true},
    {'q',"wyjdz",true},
    {'u',"wyswietl uzytkownikow",true},
    {'l',"zaloguj",true},
    {'w',"wyloguj", false},
    {'c',"czatuj",false}}
{
}

void baza::wyswietl_opcje()
{
    for (int i = 0; i<opcje.size(); ++i)
    {
        if (opcje[i].aktywna) opcje[i].wyswietl();
    }
}

void baza::aktywuj_opcje(char wybor)
{
    for (int i = 0; i<opcje.size(); ++i)
    {
        if (opcje[i].wybor==wybor)
            opcje[i].aktywna = true;
    }
}

void baza::dezaktywuj_opcje(char wybor)
{
    for (int i = 0; i<opcje.size(); ++i)
    {
        if (opcje[i].wybor==wybor)
            opcje[i].aktywna = false;
    }
}

bool baza::wybor_prawidlowy(char wybor)
{
    for (int i = 0; i<opcje.size(); ++i)
    {
        if (opcje[i].aktywna && opcje[i].wybor==wybor)
            return true;
    }
    return false;
}

void baza::dodaj_uzytkownika()
{
    uzytkownik U;
    U.pobierzdane();
    ksiazka.push_back(U);
}

void baza::wyswietl_uzytkownikow()
{
    for (int i = 0; i<ksiazka.size(); ++i)
    {
        ksiazka[i].wyswietl();
    }
}
void baza::wczytaj_uzytkownikow()
{
    fstream plik;
    plik.open("uzytkownicy.txt");
    string login, haslo;
    while (!plik.eof())
    {
        getline(plik, login);
        getline(plik, haslo);
        ksiazka.push_back({login,haslo});
    }
}
void baza::logowanie()
{
    string login, haslo;
    cout<<"Podaj login\n";
    cin>>login;
    uzytkownik* tymczas = znajdz(login);
    while (tymczas==NULL)
    {
        cout<<"nie ma takiego uzytkownika (wybierz q, aby wyjsc)\n";
        cin>>login;
        tymczas = znajdz(login);
        if (login=="q")
        {
            baza::wyjscie();
        }
    }

    cout<<"Podaj haslo\n";
    cin>>haslo;
    while (tymczas->haslo!=haslo)
    {
        cout<<"Haslo nieprawidlowe, podaj jeszcze raz lub wybierz q, aby wyjsc\n";
        cin>>haslo;
        if (haslo=="q")
        {
            baza::wyjscie();
        }
    }
    cout<<"Haslo prawidlowe\n";
    zalogowany = tymczas;
    aktywuj_opcje('c');
    aktywuj_opcje('w');
}
void baza::wyloguj()
{
    zalogowany = nullptr;
    dezaktywuj_opcje('l');
    dezaktywuj_opcje('w');
}
uzytkownik* baza::znajdz(string login)
{
    for (int i = 0; i<ksiazka.size(); ++i)
    {
        if (ksiazka[i].login==login)
            return &ksiazka[i];
    }
    return NULL;
}
void baza::interfejs()
{
    char wybor;
    wyswietl_opcje();
    cin>>wybor;

    while (wybor!='q')
    {
        while (!wybor_prawidlowy(wybor))
        {
            cout<<"Podaj jeszcze raz\n";
            cin>>wybor;
        }
        if (wybor=='d')
        {
            dodaj_uzytkownika();
        }
        if (wybor=='u')
        {
            wyswietl_uzytkownikow();
        }
        if (wybor=='l')
        {
            logowanie();
        }
        if (wybor=='c')
        {
            czat();
        }
        if (wybor=='w')
        {
            wyloguj();
        }
        wyswietl_opcje();
        cin>>wybor;
    }
}
void baza::czat()
{
    string login;
    cout<<"Podaj login\n";
    cin>>login;
    uzytkownik* rozmowca = znajdz(login);
    while (rozmowca==NULL)
    {
        cout<<"nie ma takiego uzytkownika (wybierz q, aby wyjsc/ u, aby wyswietlic uzytkownikow)\n";
        cin>>login;
        rozmowca = znajdz(login);
        if (login=="q")
        {
            baza::wyjscie();
        }
        if (login=="u")

        {
            cout<<endl;
            baza::wyswietl_uzytkownikow();
        }
    }

    string wiadomosc;

    fstream zapis_czatu;
    char input[100];
    zapis_czatu.open("zapis_czatu.txt", fstream::out | fstream::ate | fstream::app);

    cin.getline(input, 100);
    while (true)
    {
        cout<<zalogowany->login<<": ";
        cin.getline(input, 100);
        wiadomosc.assign(input);
        if (wiadomosc=="koniec") break;
        else zapis_czatu<<zalogowany->login<<": "<<wiadomosc<<endl;
        cout<<rozmowca->login<<": ";
        cin.getline(input, 100);
        wiadomosc.assign(input);
        if (wiadomosc=="koniec") break;
        else zapis_czatu<<rozmowca->login<<": "<<wiadomosc<<endl;
    }
    zapis_czatu.close();

}
void baza::wyjscie()
{
    getchar();
    getchar();
    system("cls");
    baza::interfejs();
}
