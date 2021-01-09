#include "Swiat.h"
#include "Roslina.h"

Roslina::Roslina() {
    inicjatywa = 0;
    sila = 0;
    znak = "]";
}

void Roslina::akcja() {
    if (rand() % 100 < 20) {
        swiat->rozmnorz(*this);
    }
}

//void Roslina::rozmnorz() {
//    int wolnyRzad, wolnaKolumna;
//    swiat->znajdzWolneMiejsceObok();
//
//}
void Roslina::kolizja(Organizm& wchodzacy) {

    auto komunikat = std::vector<std::string>();
    komunikat.push_back(wchodzacy.znak);
    komunikat.emplace_back("\U0001F374");
    komunikat.push_back(this->znak);
    Ekran::instancja()->wstawKomunikat(komunikat);
    swiat->zabij(*this);
    swiat->idz(wchodzacy, pozycja);
}
