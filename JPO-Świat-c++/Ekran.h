#ifndef JPO_SWIAT_EKRAN_H
#define JPO_SWIAT_EKRAN_H
#include <vector>
#include <string>
#include "Pozycja.h"

class Ekran {
private:
    std::string plansza[20][20];

    unsigned int tura;
    std::vector<std::vector<std::string>> komunikaty;
public:
    Ekran();

    void wstawZnak(std::string znak, Pozycja pozycja);

    void wyswietl();

    static Ekran* instancja();

    void wstawTure(unsigned int tura);

    void wstawKomunikat(std::vector<std::string> komunikat);
private:

    void wstawZnakiGracza();

    void wstawKomunikaty();
    void wyswietlDivider();
};

#endif //JPO_SWIAT_EKRAN_H