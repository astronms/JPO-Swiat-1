#include "Wilk.h"

Wilk::Wilk() {
    podwojnyRuch = false;
    sila = 9;
    inicjatywa = 5;
    znak = "\033[1;31mW\033[0m";
}

Organizm* Wilk::dziecko() {
    return new Wilk();
}
