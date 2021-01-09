#include "Mlecz.h"

Mlecz::Mlecz() {
    znak = "I";
}

Organizm* Mlecz::dziecko() {
    return new Mlecz();
}

void Mlecz::akcja() {
    Roslina::akcja();
    Roslina::akcja();
    Roslina::akcja();
}