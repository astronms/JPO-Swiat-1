#include "Leniwiec.h"

Leniwiec::Leniwiec() {
    podwojnyRuch = false;
    spi = false;
    sila = 2;
    inicjatywa = 1;
    znak = "V";
}

Organizm* Leniwiec::dziecko() {
    return new Leniwiec();
}

void Leniwiec::akcja() {
    spi = !spi;
    if (!spi) {
        Zwierze::akcja();
    }
}