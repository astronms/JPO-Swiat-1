#include "Guarana.h"
#include "Zwierze.h"

Guarana::Guarana() {
    znak = "\033[1;33mG\033[0m";
}

Organizm* Guarana::dziecko() {
    return new Guarana();
}

void Guarana::kolizja(Organizm& wchodzacy) {
    reinterpret_cast<Zwierze&>(wchodzacy).zwiekszSile();
    Roslina::kolizja(wchodzacy);
}