//
// Created by 48519 on 15.06.2022.
//

#ifndef PROJEKT_KOMPUTER_H
#define PROJEKT_KOMPUTER_H

#include "Gracz.h"

class Komputer : public Gracz {
private:
    ATRYBUT wybierzAtrybut();
    POZIOM_TRUDNOSCI poziomTrudnosci;

public:
    ///Konstruktor klasy Komputer
    ///@param maxIloscStworzen maksymalna posiadana ilosc stworzen
    ///@param poziomTrudnosci poziom trudnosci komputera
    Komputer(int maxIloscStworzen, POZIOM_TRUDNOSCI poziomTrudnosci);

    ///Komputer wybiera okreslona decyzje na podstawie okreslonych warunkow
    ///@return decyzja komputera (atak, ewolucja, wymiana)
    AKCJA podejmijDecyzje() override;

    ///Wykonuje atak komputera na stworzeniu
    ///@param wrog stworzenie ktore zostanie zaatakowane
    ///@return wynik ataku w formie obiektu wiadomosci
    Wynik atakuj(Stworzenie* wrog) override;

    ///Komputer decyduje o wymianie stworzenia
    void wymiana() override;

    ///Komputer decyduje o ewolucji stworzenia
    void ewolucja() override;

    ///Komputer wybiera stworzenia z puli dostepnych
    ///@param repozytorium dostepna pula wszystkich stworzen
    void wybierzStworzenia(const RepozytoriumStworzen &repozytorium) override;
};


#endif //PROJEKT_KOMPUTER_H
