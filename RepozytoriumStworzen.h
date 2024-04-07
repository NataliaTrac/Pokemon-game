//
// Created by 48519 on 14.06.2022.
//

#ifndef PROJEKT_REPOZYTORIUMSTWORZEN_H
#define PROJEKT_REPOZYTORIUMSTWORZEN_H

#include "Stworzenie.h"
#include <vector>
#include <iostream>
using std::vector;
using std::ostream;

const double WSP_SILY_POZIOM_SREDNI = 0.4;
const double WSP_ZRECZNOSCI_POZIOM_SREDNI = 0.3;
const double WSP_HP_POZIOM_SREDNI = 0.6;
const double WSP_WARTOSC_MOCY_POZIOM_SREDNI = 0.6;
const int DODATKOWA_ILOSC_UZYC_POZIOM_SREDNI = 1;

const double WSP_SILY_POZIOM_TRUDNY = 0.8;
const double WSP_ZRECZNOSCI_POZIOM_TRUDNY = 0.6;
const double WSP_HP_POZIOM_TRUDNY = 0.8;
const double WSP_WARTOSC_MOCY_POZIM_TRUDNY = 0.8;
const int DODATKOWA_ILOSC_UZYC_POZIOM_TRUDNY = 1;

class RepozytoriumStworzen {
private:
    vector<Stworzenie*> stworzenia;
    POZIOM_TRUDNOSCI poziomTrudnosci;

public:
    ///Konstruktor klasy RepozytoriumStworzen
    ///@param poziomTrudnosci poziom trundnosci stworzen
    RepozytoriumStworzen(POZIOM_TRUDNOSCI poziomTrudnosci);
    RepozytoriumStworzen(const RepozytoriumStworzen& repozytorium);
    RepozytoriumStworzen& operator=(const RepozytoriumStworzen& repozytorium);
    ~RepozytoriumStworzen();

    ///Usuwa stworzenia z repozytorium
    void usunStworzenia();

    Stworzenie* getStworzenie(int index) const;
    int iloscStworzen() const;

    friend ostream& operator<<(ostream& os, const RepozytoriumStworzen& repozytorium);
};

ostream& operator<<(ostream& os, const RepozytoriumStworzen& repozytorium);

#endif //PROJEKT_REPOZYTORIUMSTWORZEN_H
