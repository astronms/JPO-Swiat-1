#include "ZnakKolor.h"

ZnakKolor::ZnakKolor(std::string nowaZawartosc) {
    kolor = "";
    ustawZawartosc(nowaZawartosc);
}

ZnakKolor& ZnakKolor::ustawZawartosc(std::string nowaZawartosc) {
    zawartosc = nowaZawartosc;
    return *this;
}

ZnakKolor& ZnakKolor::ustawKolor(std::string nowyKolor) {
    kolor = nowyKolor;
    return *this;
}

std::string ZnakKolor::toString() {
    std::string doWypisania;

    //    if (zawartosc.size() == 0) {
    //        doWypisania = "  ";
    //    } else if (zawartosc.size() == 1) {
    //        doWypisania = zawartosc + " ";
    //    } else {
    //        doWypisania = zawartosc;
    //    }

    doWypisania = zawartosc;
    if (kolor.empty()) {
        return doWypisania;
    }
    else {
        return "\033[48;5;" + kolor + "m" + doWypisania + "\e[0m";
    }

}
