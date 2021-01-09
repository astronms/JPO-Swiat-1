#include "Lis.h"

Lis::Lis() {
    podwojnyRuch = false;
    dobryWech = true;
    sila = 2;
    inicjatywa = 1;
    znak = "\033[1;33mj\033[0m";
}

Organizm* Lis::dziecko() {
    return new Lis();
}

void Lis::akcja() {
    Zwierze::akcja();
}