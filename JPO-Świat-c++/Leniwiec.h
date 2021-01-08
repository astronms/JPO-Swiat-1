#pragma once
#include "Zwierze.h"

class Leniwiec : public Zwierze {
    bool spi;
public:
    Leniwiec();
    Organizm* dziecko();
    void akcja();
};