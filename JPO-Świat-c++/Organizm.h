﻿#pragma once

#include <vector>
#include <string>
#include "Pozycja.h"

class Swiat;

class Organizm {
protected:
    Swiat* swiat;
    unsigned int urodziny;
    int sila;
    int inicjatywa;
public:
    bool zyje;
    std::string znak;

    Organizm();

    virtual Organizm* dziecko() = 0;

    virtual void akcja() = 0;

    virtual void kolizja(Organizm& wchodzacy) = 0;

    virtual void rysowanie();

    void zarejestrujSwiat(Swiat* swiat);

    int jakaInicjatywa();
    int jakaSila();
    unsigned int wiek();

    Pozycja pozycja;
};

