//
// Created by 48519 on 15.06.2022.
//

#ifndef PROJEKT_CZLOWIEK_H
#define PROJEKT_CZLOWIEK_H

#include "Gracz.h"
#include "Input.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Czlowiek : public Gracz {
public:
    ///Konstruktor argumentowy
    ///@param maxIloscStworzen maksymalna posiadana ilosc stworzen
    Czlowiek(int maxIloscStworzen);

    ///Wyswietla wybor opcji dla gracza (atak, ewolucja, wymiana) i pobiera decyzje
    ///@return decyzja gracza (atak, ewolucja, wymiana)
    AKCJA podejmijDecyzje() override;

    ///Wykonuje atak na stworzeniu
    ///@param wrog stworzenie ktore zostanie zaatakowane
    ///@return wynik ataku w formie obiektu wiadomosci
    Wynik atakuj(Stworzenie *wrog) override;

    ///Wyswietla dla gracza opcje wymiany stworzen, dokonuje wymiany
    void wymiana() override;

    ///Ewoluuje stworzenie
    void ewolucja() override;

    ///Wyswietla dla gracza dostepne stworzenia i pobiera decyzje o wyborze stworzen do puli gracza
    ///@param repozytorium dostepna pula wszystkich stworzen
    void wybierzStworzenia(const RepozytoriumStworzen &repozytorium) override;
};


#endif //PROJEKT_CZLOWIEK_H
