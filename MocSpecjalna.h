//
// Created by 48519 on 17.06.2022.
//

#ifndef PROJEKT_MOCSPECJALNA_H
#define PROJEKT_MOCSPECJALNA_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::to_string;

enum TYP_MOCY_SPECIALNEJ {
    MOC_ATAK, MOC_OBRONA
};

const string nazwyTypowMocySpecialnych[] {
    "Atak", "Obrona"
};

class MocSpecjalna {
private:
    int iloscUzyc;
    int maxIloscUzyc;
    string nazwa;
    int wartosc;
    TYP_MOCY_SPECIALNEJ typMocySpecialnej;

public:
    ///Konstruktor klasy MocSpecjalna
    ///@param maxIloscUzyc maksymalna ilosc uzyc na walke
    ///@param nazwa nazwa mocy specjalnej
    ///@param wartosc wartosc mocy specjalnej
    ///@param typMocySpecialnej typ mocy specjalnej
    MocSpecjalna(int maxIloscUzyc, const string &nazwa, int wartosc,
                 TYP_MOCY_SPECIALNEJ typMocySpecialnej);

    int getWartosc() const;

    int getIloscUzyc() const;

    int getMaxIloscUzyc() const;

    TYP_MOCY_SPECIALNEJ getTypMocySpecialnej() const;

    const string &getNazwa() const;

    ///Zmiejsza ilosc uzyc mocy specjalnej
    void uzyj();

    ///Przywraca ilosc uzyc mocy specjalnej do stanu maksymalnego
    void przywroc();

    ///Zwieksza ilosc uzyc oraz maksymalna ilosc uzyc o 1
    void ewolucja();

    ///Zamienia dane na napis w formacie CSV (separatorem jest srednik)
    ///@return napis z danymi o mocy specjalnej
    string toCSV() const;

    friend ostream& operator<<(ostream& os, const MocSpecjalna& mocSpecjalna);
};

ostream& operator<<(ostream& os, const MocSpecjalna& mocSpecjalna);

#endif //PROJEKT_MOCSPECJALNA_H
