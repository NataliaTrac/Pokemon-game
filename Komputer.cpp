//
// Created by 48519 on 15.06.2022.
//

#include "Komputer.h"
#include "Random.h"

AKCJA Komputer::podejmijDecyzje() {
    AKCJA akcja = (AKCJA)Random::getInstance().randInt(0, ILOSC_AKCJI-1);
    while((!wybrane->czyMoznaEwoluowac() && akcja == EWOLUCJA)
            || (!wybrane->czyZemdlal() && akcja == WYMIANA)) //losujemy inna akcje jesli wybrano ewolucje a nie mozemy w danej chwili ewoluowac
    {
        akcja = (AKCJA)Random::getInstance().randInt(0, ILOSC_AKCJI-1);
    }
    return akcja;
}

Wynik Komputer::atakuj(Stworzenie* wrog) {
    bool atakSpecjalny = false;
    if(wybrane->getMocSpecjalna()->getTypMocySpecialnej() == TYP_MOCY_SPECIALNEJ::MOC_ATAK)
    {
        atakSpecjalny = (AKCJA)Random::getInstance().randInt(0, 1);
    }

    return wybrane->zadajCios(*wrog, atakSpecjalny);
}

void Komputer::wymiana() {
    if(wybrane->czyZemdlal())
    {
        for(auto stworzenie : stworzenia)
        {
            if(!stworzenie->czyZemdlal())
            {
                wybrane = stworzenie;
                break;
            }
        }
    }
}

void Komputer::ewolucja() {
    wybrane->ewolucja(wybierzAtrybut(), wybierzAtrybut());
}

ATRYBUT Komputer::wybierzAtrybut() {
    ATRYBUT atrybut = (ATRYBUT)Random::getInstance().randInt(0, ILOSC_ATRYBUTOW-1);
    return atrybut;
}

void Komputer::wybierzStworzenia(const RepozytoriumStworzen &repozytorium) {

    for(int i = 0; i < maxIloscStworzen; i++)
    {
        int index = Random::getInstance().randInt(0, repozytorium.iloscStworzen() - 1);
        auto stworzenie = repozytorium.getStworzenie(index);
        while(!dodajStworzenie(stworzenie))
        {
            index = Random::getInstance().randInt(0, repozytorium.iloscStworzen() - 1);
            stworzenie = repozytorium.getStworzenie(index);
        }
    }
}

Komputer::Komputer(int maxIloscStworzen, POZIOM_TRUDNOSCI poziomTrudnosci) : Gracz(maxIloscStworzen),
                                                                             poziomTrudnosci(poziomTrudnosci) {}
