#pragma once
#include <string>

using namespace std;

class OpcjaMenu
{
public:
	char wybor;
	string opis;
	bool aktywna;

	OpcjaMenu();
	OpcjaMenu(char wybor, string opis, bool aktywna=true);

	void wyswietl();

	~OpcjaMenu();
};

