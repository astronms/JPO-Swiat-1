#include "Wilk.h"

Wilk::Wilk() {
    podwojnyRuch = false;
    sila = 9;
    inicjatywa = 5;
    znak = "M";
}

Organizm* Wilk::dziecko() {
    return new Wilk();
}
