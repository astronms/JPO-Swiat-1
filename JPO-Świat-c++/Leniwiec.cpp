#include "Leniwiec.h"

Leniwiec::Leniwiec() {
    podwojnyRuch = false;
    spi = false;
    sila = 2;
    inicjatywa = 1;
    znak = "\033[1;96mL\033[0m";
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