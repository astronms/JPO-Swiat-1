#include "Ciern.h"

Ciern::Ciern() {
    znak = "\033[1;34m^\033[0m";
}

Organizm* Ciern::dziecko() {
    return new Ciern();
}

void Ciern::akcja() {
    Roslina::akcja(true);
}
