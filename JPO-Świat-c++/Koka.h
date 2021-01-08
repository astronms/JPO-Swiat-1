#pragma once
#include "Roslina.h"

class Koka : public Roslina {
public:
    Koka();
    Organizm* dziecko();
    void kolizja(Organizm& wchodzacy);
};
