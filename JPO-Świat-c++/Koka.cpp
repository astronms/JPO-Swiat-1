#include "Koka.h"
#include "Zwierze.h"

Koka::Koka() {
    znak = "K";
}

Organizm* Koka::dziecko() {
    return new Koka();
}

void Koka::kolizja(Organizm& wchodzacy) {
    reinterpret_cast<Zwierze&>(wchodzacy).dajBuffaPodwojnegoRuchu();
    Roslina::kolizja(wchodzacy);
}