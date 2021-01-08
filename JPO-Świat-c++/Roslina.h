#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
public:
    Roslina();

    void akcja();

    void kolizja(Organizm& wchodzacy);
};

