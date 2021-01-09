#include "Ekran.h"
#include <cstdio>

#include <utility>
#include "iostream"

using std::string;

Ekran::Ekran() {
    tura = 0;
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
    system("cls");
    std::cout << "autor: Maciej Stępień 148339\n";
    std::cout << "tura: " << tura << "\n";
    wyswietlDivider();
    wstawZnakiGracza();
    wyswietlDivider();
    std::cout << std::endl << "Legenda: \n";
    std::cout << " Rośliny: \033[1;32mT-trawa\033[0m \033[1;33mG-Guarana\033[0m \033[1;34m^-Cierń\033[0m\n";
	std::cout << " Zwierzęta: \033[1;33mj-lis\033[0m \033[1;96mL-leniwiec\033[0m O-owca  \033[1;31mW-wilk\033[0m \033[1;32mZ-żaba\033[0m\n";

    wstawKomunikaty();
}



void Ekran::wstawZnakiGracza() {
    std::cout << "\n";
    
    for (int rzad = 0; rzad < 20; rzad++) {
        for (int kolumna = 0; kolumna < 20; kolumna++) {
            if(plansza[rzad][kolumna]=="  ")
            {
                std::cout << "\033[1;100mx\033[0m";
            }else
            {
                std::cout << plansza[rzad][kolumna];
               
            }
        	
        }
        std::cout << std::endl;
    };
}


void Ekran::wstawKomunikaty() {
    std::cout << "Komunikaty :\n";
	for (auto komunikat : komunikaty) {
        
        for (int i = 0; i < komunikat.size(); i++) {
            auto literka = komunikat[i];
            std::cout << literka << std::endl;   
        }
    }
    komunikaty.clear();
}

Ekran* Ekran::instancja() {
    static Ekran instancja;
    return &instancja;
}

void Ekran::wstawKomunikat(std::vector<std::string> komunikat) {
    komunikaty.emplace_back(komunikat);
}

void Ekran::wyswietlDivider()
{
    std::cout << "---------------------------------\n";
}

