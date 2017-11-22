#include "OpcjaMenu.h"
#include <iostream>

OpcjaMenu::OpcjaMenu():
	wybor{0}, opis{""}, aktywna{false}
{
}

OpcjaMenu::OpcjaMenu(char wybor, string opis, bool aktywna):
	wybor{wybor}, opis{opis}, aktywna{aktywna}
{
}

void OpcjaMenu::wyswietl()
{
	cout<<wybor<<" - "<<opis<<endl;
}

OpcjaMenu::~OpcjaMenu()
{
}
