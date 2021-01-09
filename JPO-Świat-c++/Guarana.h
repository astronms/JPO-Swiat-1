#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
    Guarana();
    Organizm* dziecko();
    void kolizja(Organizm& wchodzacy);
};