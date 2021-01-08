#pragma once
#include <vector>
#include "Ekran.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"  


class Swiat {
private:
    unsigned int tura;
    std::vector<Organizm*> organizmy;

    unsigned int korygatorWspolrzednej(int wspolrzedna);

    Organizm* rozmnorz(Organizm& organizm, unsigned int zasieg);

    void ustawKolejnoscWalk();
    void usunMartweOrganizmy();
    void weryfikujCzyWszystkoGit();
public:
    Swiat();

    void wykonajTure();

    unsigned int ktoraTura();

    void rysujSwiat();

    void dodajOrganizm(Organizm* organizm);

    void idz(Organizm& organizm, Pozycja pozycja);

    void zabij(Organizm& organizm);

    Organizm* znajdz(Pozycja pozycja);

    Zwierze* rozmnorz(Zwierze& pasywny, Zwierze& inicjator);

    Roslina* rozmnorz(Roslina& roslina);

    bool znajdzWolneMiejsceObok(unsigned int zasieg, Pozycja pozycja, Pozycja& wybranaPozycja);

};

//struct wspolrzedne {
//    int rzad;
//    int kolumna;
//};