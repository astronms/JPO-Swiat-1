#pragma once
#include <string>

class ZnakKolor {
private:
    std::string zawartosc;
    std::string kolor;
public:
    ZnakKolor(std::string nowaZawartosc);

    ZnakKolor& ustawZawartosc(std::string nowaZawartosc);

    ZnakKolor& ustawKolor(std::string nowyKolor);

    std::string toString();
};
