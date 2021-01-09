#include "Trawa.h"


Trawa::Trawa() {
    znak = "W";
}

Organizm* Trawa::dziecko() {
    return new Trawa();
}