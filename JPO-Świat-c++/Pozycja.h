#pragma once
class Pozycja {
private:
    unsigned int _rzad;
    unsigned int _kolumna;
public:
    Pozycja();

    Pozycja(int rzad, int kolumna);

    bool operator==(const Pozycja) const;

    unsigned int rzad();

    unsigned int kolumna();

    unsigned int jednowymiarowo();

    Pozycja* obok(unsigned int zakres);
};