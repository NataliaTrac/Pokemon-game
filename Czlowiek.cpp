//
// Created by 48519 on 15.06.2022.
//

#include "Czlowiek.h"

Czlowiek::Czlowiek(int maxIloscStworzen) : Gracz(maxIloscStworzen) {}

AKCJA Czlowiek::podejmijDecyzje() {
    cout << "Podejmij decyzje: 1. Atak, 2. Ewolucja, 3. Wymiana" << endl; //to zrealizowac za pomoca komendy tekstowej
    AKCJA akcja = (AKCJA)(Input::wczytajLiczbe(1, ILOSC_AKCJI) - 1);
    return akcja;
}

Wynik Czlowiek::atakuj(Stworzenie *wrog) {
    bool atakSpecjalny = false;
    if(wybrane->getMocSpecjalna()->getTypMocySpecialnej() == TYP_MOCY_SPECIALNEJ::MOC_ATAK && wybrane->getMocSpecjalna()->getIloscUzyc() > 0)
    {
        cout << "Wykonac atak specjalny? 1. Tak 0. Nie" << endl;
        atakSpecjalny = Input::wczytajLiczbe(0, 1);
    }

    return wybrane->zadajCios(*wrog, atakSpecjalny);
}

void Czlowiek::wymiana() {
    cout << "Wybierz nr stworzenia do wymiany: " << endl;
    for(int i = 0; i < stworzenia.size(); i++)
    {
        cout << (i+1) << ". " << *stworzenia[i] << endl;
    }
    int index = Input::wczytajLiczbe(1, stworzenia.size()) - 1;
    while(stworzenia[index]->czyZemdlal())
    {
        cout << "Wybrane stworzenie nie nadaje sie do walki, wybierz inne" << endl;
        index = Input::wczytajLiczbe(1, stworzenia.size()) - 1;
    }
    wybrane = stworzenia[index];
}

void Czlowiek::ewolucja() {
    cout << "Dostepne atrybuty: " << endl;
    for(int i = 0; i < ILOSC_ATRYBUTOW; i++)
    {
        cout << (i+1) << ". " << nazwyAtrybutow[i] << endl;
    }
    cout << "Podaj nr pierwszego atrybutu" << endl;
    ATRYBUT atrybut1 = (ATRYBUT)(Input::wczytajLiczbe(1, ILOSC_ATRYBUTOW) - 1);
    cout << "Podaj nr drugiego atrybutu" << endl;
    ATRYBUT atrybut2 = (ATRYBUT)(Input::wczytajLiczbe(1, ILOSC_ATRYBUTOW) - 1);
    wybrane->ewolucja(atrybut1, atrybut2);
}

void Czlowiek::wybierzStworzenia(const RepozytoriumStworzen &repozytorium) {
    cout << "Lista dostepnych stworzen: " << endl;
    cout << repozytorium << endl;
    for(int i = 0; i < maxIloscStworzen; i++)
    {
        cout << "Podaj indeks stworzenia nr " << (i+1) << endl;
        int index = Input::wczytajLiczbe(1, repozytorium.iloscStworzen()) - 1;
        auto stworzenie = repozytorium.getStworzenie(index);
        while(!dodajStworzenie(stworzenie))
        {
            cout << "Wybrane stworzenie zostalo juz dodane, wybierz inne" << endl;
            index = Input::wczytajLiczbe(1, repozytorium.iloscStworzen()) - 1;
            stworzenie = repozytorium.getStworzenie(index);
        }
    }
}
