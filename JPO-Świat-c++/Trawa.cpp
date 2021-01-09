#include "Trawa.h"


Trawa::Trawa() {
    znak = "\033[1;32mT\033[0m";
}

Organizm* Trawa::dziecko() {
    return new Trawa();
}