#include "Owca.h"

Owca::Owca() {
    podwojnyRuch = false;
    sila = 4;
    inicjatywa = 4;
    znak = "\033[1;37mO\033[0m";
}

Organizm* Owca::dziecko() {
    return new Owca();
}
