#ifndef JPO_SWIAT_EKRAN_H
#define JPO_SWIAT_EKRAN_H
#include <vector>
#include <string>
#include "ZnakKolor.h"
#include "Pozycja.h"

class Ekran {
private:
    std::string plansza[20][20];

    unsigned int tura;
    std::vector<std::vector<ZnakKolor>> templatka;
    std::vector<std::vector<std::string>> komunikaty;
public:
    Ekran();

    void wstawZnak(std::string znak, Pozycja pozycja);

    void wyswietl();

    static Ekran* instancja();

    void wstawTure(unsigned int tura);

    void wstawKomunikat(std::vector<std::string> komunikat);
private:
    std::vector<std::vector<ZnakKolor>> wygenerujTemplatka();

    std::vector<std::vector<ZnakKolor>> wstawZnakiGracza(std::vector<std::vector<ZnakKolor>>);

    void wyswietlBuffer(const std::vector<std::vector<ZnakKolor>>& linie);

    std::vector<std::vector<ZnakKolor>> wstawTure(std::vector<std::vector<ZnakKolor>> kolorowaPlansza);

    std::vector<std::vector<ZnakKolor>> wstawKomunikaty(std::vector<std::vector<ZnakKolor>> kolorowaPlansza);
};

#endif //JPO_SWIAT_EKRAN_H