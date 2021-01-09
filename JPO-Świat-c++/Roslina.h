#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
public:
    Roslina();

    void akcja();
    void akcja(bool);
    //void Roslina::rozmnorz();

    void kolizja(Organizm& wchodzacy);
};

