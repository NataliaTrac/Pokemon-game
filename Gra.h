//
// Created by 48519 on 17.06.2022.
//

#ifndef PROJEKT_GRA_H
#define PROJEKT_GRA_H

#include "Komputer.h"
#include "Gracz.h"
#include "Czlowiek.h"
#include "RepozytoriumStworzen.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::ofstream;
using std::ifstream;
using std::chrono::milliseconds;
using std::this_thread::sleep_for;

enum STAN_RUNDY {
    PRZEGRANA, WYGRANA, WYJSCIE
};

class Gra {
private:
    const int GRACZ_ILOSC_STWORZEN = 6;
    const int KOMPUTER_ILOSC_STWORZEN = 4;
    const string ZAPIS_PLIK = "zapis.txt";

    RepozytoriumStworzen repozytoriumStworzen;
    Gracz* gracz;
    int aktualnaRunda;
    int bazowaIloscPrzeciwnikow;
    int iloscRund;
    int iloscDodatkowychPrzeciwnikow;
    int aktualnyPrzeciwnik;
    POZIOM_TRUDNOSCI poziomTrudnosci;
    bool walka(Gracz* g1, Gracz* g2);
    STAN_RUNDY rozpocznijRudne(int iloscPrzeciwnikow);
    void stworzGracza();
    void usunGracza();
    void zapisz();

public:
    ///Konstruktor klasy Gra - na podstawie poziomu trudnosci ustawia ilosc dodatkowych przeciwnikow ktora bedzie sie zwiekszac po kazdej rundzie
    ///@param bazowaIloscPrzeciwnikow - poczatkowa ilosc przeciwnikow w pierwszej rundzie
    ///@param iloscRund - ilosc rund
    ///@param poziomTrudnosci - poziom trudnosci przeciwnikow oraz stworzen
    Gra(POZIOM_TRUDNOSCI poziomTrudnosci, int iloscRund, int bazowaIloscPrzeciwnikow);

    /// Uruchomienie rozgrywki
    void rozpocznij();

    ///Laduje gre na podstawie danych z pliku
    ///@param nazwaPliku nazwa pliku z zapisanym stanem gry
    ///@return obiekt gry stworzonej na podstawie danych z pliku
    static Gra *zaladujGre(string nazwaPliku);
};


#endif //PROJEKT_GRA_H
