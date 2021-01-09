#include "Owca.h"

Owca::Owca() {
    podwojnyRuch = false;
    sila = 4;
    inicjatywa = 4;
    znak = "O";
}

Organizm* Owca::dziecko() {
    return new Owca();
}
