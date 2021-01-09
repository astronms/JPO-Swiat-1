#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
    Lis();
    Organizm* dziecko();
    void akcja();
};