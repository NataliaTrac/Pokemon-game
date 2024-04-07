//
// Created by 48519 on 14.06.2022.
//

#ifndef PROJEKT_WYNIK_H
#define PROJEKT_WYNIK_H

#include <iostream>
using std::string;
using std::ostream;

class Wynik {
private:
    string wiadomosc;
    bool sukces;

public:
    ///Konstruktor klasy Wynik
    ///@param wiadomosc informacja przechowywana przez obiekt odnosnie wyniku dzialania programu
    ///@param sukces prawda jesli dana operacja przebiegla pomyslnie
    Wynik(const string &wiadomosc, bool sukces = false);
    bool isSukces() const;

    const string &getWiadomosc() const;

    void setWiadomosc(const string &wiadomosc);

    void setSukces(bool sukces);

    friend ostream& operator<<(ostream& os, const Wynik& wynik);
};

ostream& operator<<(ostream& os, const Wynik& wynik);


#endif //PROJEKT_WYNIK_H
