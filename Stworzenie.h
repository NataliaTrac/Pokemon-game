//
// Created by 48519 on 26.04.2022.
//
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include "Random.h"
#include "Wynik.h"
#include "MocSpecjalna.h"
using std::ostream;
using std::string;
using std::to_string;
using std::vector;
using std::stoi;

#ifndef PROJEKT_STWORZENIA_H
#define PROJEKT_STWORZENIA_H

enum POZIOM_TRUDNOSCI {
    LATWY, SREDNI, TRUDNY
};

enum TYP {
    WODA, ZIEMIA, POWIETRZE, OGIEN, LOD, STAL
};

///Uzwana jest do tabeli interakcji aby okreslic czy dwa typy stworzen wchodza ze soba w dodatkowe interakcje ktore powoduja
///wzrost lub spadek sily ataku i obrony
enum ZALEZNOSC {
    BRAK, KORZYSC, STRATA
};

const ZALEZNOSC interakcje[][6] = {
        {STRATA, KORZYSC, BRAK, KORZYSC, BRAK, BRAK},
        {BRAK, BRAK, STRATA, KORZYSC, KORZYSC, KORZYSC},
        {BRAK, STRATA, BRAK, BRAK, KORZYSC, STRATA},
        {STRATA, STRATA, BRAK, BRAK, KORZYSC, KORZYSC},
        {STRATA, KORZYSC, BRAK, STRATA, STRATA, BRAK},
        {KORZYSC, BRAK, KORZYSC, STRATA, BRAK, STRATA}
};

const int ILOSC_ATRYBUTOW = 4;

enum ATRYBUT {
    SILA, ZRECZNOSC, HP, MOC_SPECJALNA
};

const string nazwyAtrybutow[] = {"Sila", "Zrecznosc", "HP", "Moc specjalna"};
const string nazwyTypow[] = {"Woda", "Ziemia", "Powietrze", "Ogien", "Lod", "Stal"};
const int tabelaExp[] = {0, 100, 200, 400, 500, 1000, 2000, 10000};

///Wartosc dodatkowa o ktora zostanie powiekszony atak w przypadku gdy stworzenia wejda w okreslona interakcje wynikajaca z tabeli interakcji
const int DODATKOWA_SILA_ATAKU = 2;

///Wartosc expa za pokonanego przeciwnika per jego lvl
const int EXP_PER_LVL = 100;

///Wartosc dodatkowa o ktora zostanie powiekszona obrona w przypadku gdy stworzenia wejda w okreslona interakcje wynikajaca z tabeli interakcji
const int DODATKOWA_SILA_OBRONY = 2;

///Wartosc zwiekszenia sily po ewolucji
const int DODATKOWA_SILA = 2;

///Wartosc zwiekszenia zrecznosci po ewolucji
const int DODATKOWA_ZRECZNOSC = 2;

///Wartosc zwiekszenia hp po ewocji
const int DODATKOWE_HP = 25;

class Stworzenie {
private:
    MocSpecjalna* mocSpecjalna;
    string nazwa;
    int sila, zrecznosc, hp, maxHp, exp, lvl;
    TYP typ;
    void ulepsz(ATRYBUT atrybut);
    //zrecznosc 0-100 gdzie 0 - przyjmuje kazdy cios 100- unika kazdego ciosu

public:
    ///Konsturktor klasy Stworzenie
    ///@param nazwa nazwa stworzenia
    ///@param sila sila ataku stworzenia
    ///@param zrecznosc szansa na unikniecie ataku (wartosc z przedzialu [0, 100] gdzie 100 to calkowita odpornosc)
    ///@param maxHp maksymalna ilosc punktow zycia
    ///@param typ typ stworzenia
    ///@param mocSpecjalna moc specjalna stworzenia
    Stworzenie(string nazwa, int sila, int zrecznosc, int maxHp, TYP typ, MocSpecjalna* mocSpecjalna);
    Stworzenie(const Stworzenie& stworzenie);
    Stworzenie& operator=(const Stworzenie& stworzenie);
    ~Stworzenie();

    ///Zadaje cios dla stworzenia przekazanego w argumencie
    ///@param przeciwnik stworzenie ktore otrzyma cios
    ///@param czySpecjalny prawda jesli ma byc wykonany atak specjalny
    ///@return obiekt wiadomosci z wynikiem ataku
    Wynik zadajCios(Stworzenie& przeciwnik, bool czySpecjalny = false);

    ///Przyjmuje cios od innego przeciwnika
    ///@param atakujacy stworzenie ktore wykonuje atak
    ///@param silaHp sila ataku
    ///@return obiekt wiadomosci z wynikiem obrony
    Wynik przyjmijCios(Stworzenie& atakujacy, int silaHp);

    ///Ulepsza wybrane dwa atrybuty, podnosi poziom
    ///@param a1 atrybut do ulepszenia
    ///@param a2 atrybut do ulepszenia
    ///@return prawda jesli udalo sie ulepszyc stworzenie
    bool ewolucja(ATRYBUT a1, ATRYBUT a2);

    ///Przywraca punkty zycia i moc specjalna dla stworzenia
    void ocuc();

    ///Sprawdza czy mozna przeprowadzic ewolucje stworzenia
    ///@return prawda jesli mozna ewoluowac stworzenie
    bool czyMoznaEwoluowac() const;

    ///Spawdza czy stowrzenie posiada 0 punktow zycia (zemdlalo)
    ///@return prawda jesli stworzenie posiada 0 punktow zycia
    bool czyZemdlal() const;
    bool operator==(const Stworzenie& stworzenie) const;

    MocSpecjalna *getMocSpecjalna() const;

    ///Przeksztalca dane o stworzeniu do postaci tekstu w formacie CSV (separator - srednik)
    ///@return dane o stworzeniu w formie tekstu
    string toCSV() const;

    friend ostream& operator<<(ostream& os, const Stworzenie& stworzenie);

    ///Tworzy stworzneie na podstawie danych z tekstu (linia CSV z srednikiem jako separator)
    ///@param linia tekstu z danymi o stworzeniu
    ///@return obiekt stworzenia powstalego na podstawie danych tekstowych
    static Stworzenie *zaladuj(string daneStr);
};

ostream& operator<<(ostream& os, const Stworzenie& stworzenie);

#endif //PROJEKT_STWORZENIA_H
