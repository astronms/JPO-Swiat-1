﻿//
// Created by johnny on 23/11/2020.
//

#include "Ekran.h"
#include <stdio.h>

#include <utility>
#include "iostream"

using std::string;

Ekran::Ekran() {
    tura = 0;
    templatka = wygenerujTemplatka();
    for (auto& rzad : plansza) {
        for (auto& kolumna : rzad) {
            kolumna = "  ";
        }
    };
}

void Ekran::wstawTure(unsigned int tura) {
    this->tura = tura;
}
void Ekran::wstawZnak(std::string znak, Pozycja pozycja) {
    plansza[pozycja.rzad()][pozycja.kolumna()] = znak;
}

void Ekran::wyswietl() {
    auto plansza = wstawKomunikaty(wstawTure(wstawZnakiGracza(templatka)));
    system("clear");
    wyswietlBuffer(plansza);
}

std::vector<std::vector<KolorowyZnak>> Ekran::wygenerujTemplatka() {
    std::vector<std::string> asciiPlansza;

    asciiPlansza.emplace_back("                                                                   \n");
    asciiPlansza.emplace_back(" 1xxxxxxxxxxxxxxxxxx3 ╔══════════════════════════════════════════╗ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx ║          Andrzej Bisewski 182619         ║ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx ╚══════════════════════════════════════════╝ \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx  Tura:                                       \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx  Komunikaty:                                 \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back(" xxxxxxxxxxxxxxxxxxxx                                              \n");
    asciiPlansza.emplace_back("                                                                   \n");
    asciiPlansza.emplace_back(" \U0001F344 \u2190 koka     \U0001F331 \u2190 mlecz \U0001F33E \u2190 trawa\n");
    asciiPlansza.emplace_back(" \U0001F9A5 \u2190 leniwiec \U0001F411 \u2190 owca  \U0001F415 \u2190 wilk  \U0001F438 \u2190 żaba \U0001F40D \u2190 żmija \n");

    std::vector<std::vector<KolorowyZnak>> kolorowaPlansza;

    for (std::string rzad : asciiPlansza) {
        std::vector<KolorowyZnak> kolorowaLinia;
        for (char kolumna : rzad) {
            kolorowaLinia.emplace_back(KolorowyZnak(std::string(1, kolumna)));
        }
        kolorowaPlansza.emplace_back(kolorowaLinia);
    }

    const unsigned int RZAD_MAPY = 1;
    const unsigned int KOLUMNA_MAPY = 1;
    const std::string colors[] = { "236", "236", "236", "237", "237", "237" };
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            int v1 = rand() % 6;
            auto color = colors[v1];
            kolorowaPlansza[RZAD_MAPY + rzad][KOLUMNA_MAPY + kolumna].ustawKolor(color);
        }
    };


    return kolorowaPlansza;
}

std::vector<std::vector<KolorowyZnak>> Ekran::wstawZnakiGracza(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza) {
    const unsigned int RZAD_MAPY = 1;
    const unsigned int KOLUMNA_MAPY = 1;
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            kolorowaPlansza[RZAD_MAPY + rzad][KOLUMNA_MAPY + kolumna].ustawZawartosc(plansza[rzad][kolumna]);
        }
    };

    return kolorowaPlansza;
}

std::vector<std::vector<KolorowyZnak>> Ekran::wstawTure(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza) {
    const unsigned int RZAD_TURY = 4;
    const unsigned int KOLUMNA_TURY = 29;

    string znakiTury = std::to_string(tura);

    for (int i = 0; i < znakiTury.size(); i++) {
        kolorowaPlansza[RZAD_TURY][KOLUMNA_TURY + i].ustawZawartosc(string(1, znakiTury[i]));
    };

    return kolorowaPlansza;
}

std::vector<std::vector<KolorowyZnak>> Ekran::wstawKomunikaty(std::vector<std::vector<KolorowyZnak>> kolorowaPlansza) {

    const unsigned int RZAD_MAPY = 8;
    const unsigned int KOLUMNA_MAPY = 29;

    auto ile_w_poziomie = 0;
    auto ile_w_pionie = 0;

    for (auto komunikat : komunikaty) {
        if (ile_w_poziomie == 3) {
            ile_w_poziomie = 0;
            ile_w_pionie += 1;
        }


        if (ile_w_pionie > 11) {
            kolorowaPlansza[RZAD_MAPY + ile_w_pionie][KOLUMNA_MAPY].ustawZawartosc("i jeszcze trochę...");
            break;
        }

        for (int i = 0; i < komunikat.size(); i++) {
            auto literka = komunikat[i];
            kolorowaPlansza[RZAD_MAPY + ile_w_pionie][KOLUMNA_MAPY + ile_w_poziomie * 5 + i].ustawZawartosc(literka);
            if (komunikat.size() == 3) {
                kolorowaPlansza[RZAD_MAPY + ile_w_pionie][KOLUMNA_MAPY + ile_w_poziomie * 5 + i].ustawKolor("1");
            }
            else {
                kolorowaPlansza[RZAD_MAPY + ile_w_pionie][KOLUMNA_MAPY + ile_w_poziomie * 5 + i].ustawKolor("195");
            }
        }
        for (int i = komunikat.size(); i < 5; i++) {
            kolorowaPlansza[RZAD_MAPY + ile_w_pionie][KOLUMNA_MAPY + ile_w_poziomie * 5 + i].ustawZawartosc("  ");
        }
        ile_w_poziomie += 1;

    }

    komunikaty.clear();
    return kolorowaPlansza;
}

void Ekran::wyswietlBuffer(const std::vector<std::vector<KolorowyZnak>>& linie) {
    for (const auto& linia : linie) {
        for (auto znak : linia) {
            std::cout << znak.toString();
        }
    }
    std::cout.flush();
    for (auto& rzad : plansza) {
        for (auto& kolumna : rzad) {
            kolumna = "⠀ ";
        }
    };
};

Ekran* Ekran::instancja() {
    static Ekran instancja;
    return &instancja;
}

void Ekran::wstawKomunikat(std::vector<std::string> komunikat) {
    komunikaty.emplace_back(komunikat);
}
