//
// Created by 48519 on 17.06.2022.
//

#include "MocSpecjalna.h"

MocSpecjalna::MocSpecjalna(int maxIloscUzyc, const string &nazwa, int wartosc,
                           TYP_MOCY_SPECIALNEJ typMocySpecialnej) : iloscUzyc(maxIloscUzyc), maxIloscUzyc(maxIloscUzyc),
                                                                    nazwa(nazwa), wartosc(wartosc),
                                                                    typMocySpecialnej(typMocySpecialnej) {}

int MocSpecjalna::getWartosc() const {
    return wartosc;
}

ostream &operator<<(ostream &os, const MocSpecjalna &mocSpecjalna) {
    return os << "Moc specjalna: " << mocSpecjalna.nazwa << " ilosc: " << mocSpecjalna.iloscUzyc << "/" << mocSpecjalna.maxIloscUzyc
    << " typ: " << nazwyTypowMocySpecialnych[mocSpecjalna.typMocySpecialnej];
}

int MocSpecjalna::getIloscUzyc() const {
    return iloscUzyc;
}

int MocSpecjalna::getMaxIloscUzyc() const {
    return maxIloscUzyc;
}

TYP_MOCY_SPECIALNEJ MocSpecjalna::getTypMocySpecialnej() const {
    return typMocySpecialnej;
}

void MocSpecjalna::uzyj() {
    if(iloscUzyc > 0)
    {
        iloscUzyc--;
    }
}

void MocSpecjalna::przywroc() {
    iloscUzyc = maxIloscUzyc;
}

void MocSpecjalna::ewolucja() {
    iloscUzyc++;
    maxIloscUzyc++;
}

const string &MocSpecjalna::getNazwa() const {
    return nazwa;
}

string MocSpecjalna::toCSV() const {
    return to_string(iloscUzyc) + ";" + to_string(maxIloscUzyc) + ";" + nazwa + ";" + to_string(wartosc) + ";" +
            to_string(typMocySpecialnej);
}
