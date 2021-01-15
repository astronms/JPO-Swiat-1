#include "Zaba.h"

Zaba::Zaba() {
    podwojnyRuch = true;
    sila = 1;
    inicjatywa = 2;
    znak = "\033[1;32mZ\033[0m";
}

Organizm* Zaba::dziecko() {
    return new Zaba();
}
