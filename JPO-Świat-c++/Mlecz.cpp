#include "Mlecz.h"

Mlecz::Mlecz() {
    znak = "\U0001F331";
}

Organizm* Mlecz::dziecko() {
    return new Mlecz();
}

void Mlecz::akcja() {
    Roslina::akcja();
    Roslina::akcja();
    Roslina::akcja();
}