//
// Created by 48519 on 14.06.2022.
//

#include "Wynik.h"

Wynik::Wynik(const string &wiadomosc, bool sukces) : wiadomosc(wiadomosc), sukces(sukces) {}

ostream &operator<<(ostream &os, const Wynik &wynik) {
    return os << wynik.wiadomosc;
}

bool Wynik::isSukces() const {
    return sukces;
}

const string &Wynik::getWiadomosc() const {
    return wiadomosc;
}

void Wynik::setWiadomosc(const string &wiadomosc) {
    Wynik::wiadomosc = wiadomosc;
}

void Wynik::setSukces(bool sukces) {
    Wynik::sukces = sukces;
}
