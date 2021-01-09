﻿#include <iostream>
#include <windows.h>
#include "Swiat.h"
#include "Ekran.h"
#include "Wilk.h"
#include "Owca.h"
#include "Leniwiec.h"
#include "Trawa.h"
#include <conio.h>
#include <locale.h>

#include "Guarana.h"

#define dodaj(nazwa_zmiennaj, KLASA, rzad, kolumna) \
        Organizm * nazwa_zmiennaj = new KLASA();    \
        swiat.dodajOrganizm(nazwa_zmiennaj);        \
        swiat.idz(*nazwa_zmiennaj, Pozycja(rzad, kolumna));

int Rozmiar_a = 20;
int Rozmiar_b = 20;

int main() {
    setlocale(LC_CTYPE, "Polish");
	Swiat swiat;

    dodaj(wilk1, Wilk, 14, 1);
    dodaj(wilk2, Wilk, 13, 1);
    dodaj(wilk3, Wilk, 2, 1);
    dodaj(wilk4, Wilk, 5, 1);
    dodaj(wilk5, Wilk, 8, 1);
    dodaj(wilk6, Wilk, 17, 1);
    dodaj(owca1, Owca, 3, 3);
    dodaj(owca2, Owca, 4, 16);
    dodaj(owca3, Owca, 6, 6);
    dodaj(owca4, Owca, 14, 13);
    dodaj(guarana1, Guarana, 1, 1);
    dodaj(guarana2, Guarana, 16, 16);
    dodaj(leniwiec1, Leniwiec, 16, 10);
    dodaj(leniwiec2, Leniwiec, 15, 10);
    dodaj(leniwiec3, Leniwiec, 15, 7);
    dodaj(trawa1, Trawa, 10, 17);
    dodaj(trawa2, Trawa, 10, 18);


    for (int i = 0; i < 100000; i++) {

        swiat.rysujSwiat();
        try {
            swiat.wykonajTure();
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
            return 0;
        }
        bool Run = true;
        char znak;
        while (Run)
        {
            znak = _getch();
            if (znak == 'a') Run = false;

        }
    }
    return 0;
}
