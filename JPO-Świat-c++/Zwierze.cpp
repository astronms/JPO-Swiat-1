#include "Swiat.h"
#include "Zwierze.h"


Zwierze::Zwierze() {
    znak = "8";
    podwojnyRuch = false;
   
}

void Zwierze::akcja() {
    swiat->idz(*this, *pozycja.obok(1));
    if (podwojnyRuch) {
        podwojnyRuch = false;
        akcja();
    }
}


void Zwierze::kolizja(Organizm& wchodzacy) {
    kolizja(reinterpret_cast<Zwierze&>(wchodzacy));
}

void Zwierze::kolizja(Zwierze& wchodzacy) {
    if (znak == wchodzacy.znak) {
        swiat->rozmnorz(*this, wchodzacy);
    }
    else {
        auto komunikat = std::vector<std::string>();

        if (wchodzacy.jakaSila() >= this->jakaSila()) {
            komunikat.push_back(wchodzacy.znak + " wygrywa z " + this->znak);
            swiat->zabij(*this);
            swiat->idz(wchodzacy, pozycja);
        }
        else {
            komunikat.push_back(this->znak + " zjada " + wchodzacy.znak);
            swiat->zabij(wchodzacy);
        }

        Ekran::instancja()->wstawKomunikat(komunikat);

    }
}

void Zwierze::zwiekszSile() {
    this->sila += 3;
}