//
// Created by 48519 on 26.04.2022.
//

#include "Stworzenie.h"

Stworzenie::Stworzenie(string nazwa, int sila, int zrecznosc, int maxHp, TYP typ, MocSpecjalna* mocSpecjalna)
    : sila(sila),
        zrecznosc(zrecznosc),
        maxHp(maxHp),
        mocSpecjalna(mocSpecjalna),
        typ(typ),
        hp(maxHp),
        exp(0),
        lvl(1),
        nazwa(nazwa)
        {

        }

Wynik Stworzenie::zadajCios(Stworzenie &przeciwnik, bool czySpecjalny)  {
    if(czyZemdlal())
    {
        return Wynik(nazwa +" zemdlalo");
    }

    int silaUderzenia = sila;
    if(czySpecjalny && mocSpecjalna->getIloscUzyc() > 0 && mocSpecjalna->getTypMocySpecialnej() == TYP_MOCY_SPECIALNEJ::MOC_ATAK)
    {
        silaUderzenia += mocSpecjalna->getWartosc();
        mocSpecjalna->uzyj();
    }
    auto interakcja = interakcje[typ][przeciwnik.typ];
    switch(interakcja)
    {
        case ZALEZNOSC::KORZYSC:
            silaUderzenia = silaUderzenia + DODATKOWA_SILA_ATAKU;
            break;
        case ZALEZNOSC::STRATA:
            silaUderzenia = silaUderzenia - DODATKOWA_SILA_ATAKU;
            break;
    }
    auto wynik = przeciwnik.przyjmijCios(*this, silaUderzenia);
    if(wynik.isSukces() && przeciwnik.czyZemdlal())
    {
        exp += przeciwnik.lvl * EXP_PER_LVL;
    }
    if(czySpecjalny)
    {
        wynik.setWiadomosc(nazwa + " atakuje moca specjalna " + mocSpecjalna->getNazwa() + "\n" + wynik.getWiadomosc());
    }
    return wynik;
}

Wynik Stworzenie::przyjmijCios(Stworzenie& atakujacy, int silaHp) {
    if(czyZemdlal())
    {
        return Wynik(nazwa + " zemdlalo");
    }

    int wartoscUcieczki = Random::getInstance().randInt100();
    if(wartoscUcieczki < zrecznosc)
    {
        return Wynik(nazwa +" uniknelo ciosu");
    }

    auto interakcja = interakcje[typ][atakujacy.typ];
    switch(interakcja)
    {
        case ZALEZNOSC::KORZYSC:
            silaHp = silaHp - DODATKOWA_SILA_OBRONY;
            break;
        case ZALEZNOSC::STRATA:
            silaHp = silaHp + DODATKOWA_SILA_OBRONY;
            break;
    }

    if(mocSpecjalna->getTypMocySpecialnej() == TYP_MOCY_SPECIALNEJ::MOC_OBRONA)
    {
        const int MAX_ZAKRES_LOSOWANIA = 4;
        int aktywacja = Random::getInstance().randInt(1, MAX_ZAKRES_LOSOWANIA);
        if(aktywacja == 1)
        {
            auto wynik = atakujacy.przyjmijCios(*this, silaHp);
            wynik.setWiadomosc(nazwa + " obija atak za pomoca " + mocSpecjalna->getNazwa() + "\n" + wynik.getWiadomosc());
            return wynik;
        }
    }

    hp -= silaHp;
    string dodatkowyKomunikat = "";
    if(hp < 0)
    {
        hp = 0;
        dodatkowyKomunikat = " i zostaje pokonany";
    }
    return Wynik(nazwa + " otrzymuje atak o sile: " + to_string(silaHp) + " ma teraz hp: " + to_string(hp) + "/" +
                         to_string(maxHp) + dodatkowyKomunikat, true);
}

bool Stworzenie::ewolucja(ATRYBUT a1, ATRYBUT a2) {
    if(czyMoznaEwoluowac())
    {
        lvl++;
        ulepsz(a1);
        ulepsz(a2);
        return true;
    }
    return false;
}

bool Stworzenie::czyZemdlal() const {
    return hp == 0;
}

ostream &operator<<(ostream &os, const Stworzenie &stworzenie) {
    return os << stworzenie.nazwa << " sila: " << stworzenie.sila << " zrecznosc: " << stworzenie.zrecznosc << " HP: " << stworzenie.hp << "/" << stworzenie.maxHp
              << " " << *stworzenie.mocSpecjalna << " exp: "
              << stworzenie.exp << " typ: " << nazwyTypow[stworzenie.typ] << " lvl: " << stworzenie.lvl;
}

void Stworzenie::ocuc() {
    hp = maxHp;
    mocSpecjalna->przywroc();
}

void Stworzenie::ulepsz(ATRYBUT atrybut) {
    switch(atrybut)
    {
        case SILA:
            sila += DODATKOWA_SILA;
            break;
        case ZRECZNOSC:
            zrecznosc += DODATKOWA_ZRECZNOSC;
            break;
        case HP:
            maxHp += DODATKOWE_HP;
            hp += DODATKOWE_HP;
            break;
        case MOC_SPECJALNA:
            mocSpecjalna->ewolucja();
            break;
    }
}

bool Stworzenie::czyMoznaEwoluowac() const {
    return !czyZemdlal() && exp >= tabelaExp[lvl];
}

bool Stworzenie::operator==(const Stworzenie& stworzenie) const {
    return nazwa == stworzenie.nazwa;
}

Stworzenie::Stworzenie(const Stworzenie &stworzenie) : sila(stworzenie.sila),
                                                       zrecznosc(stworzenie.zrecznosc),
                                                       maxHp(stworzenie.maxHp),
                                                       mocSpecjalna(new MocSpecjalna(*stworzenie.mocSpecjalna)),
                                                       typ(stworzenie.typ),
                                                       hp(stworzenie.maxHp),
                                                       exp(stworzenie.exp),
                                                       lvl(stworzenie.lvl),
                                                       nazwa(stworzenie.nazwa)
{

}

Stworzenie &Stworzenie::operator=(const Stworzenie& stworzenie) {
    sila=stworzenie.sila;
    zrecznosc=stworzenie.zrecznosc;
    maxHp=stworzenie.maxHp;
    mocSpecjalna=new MocSpecjalna(*stworzenie.mocSpecjalna);
    typ=stworzenie.typ;
    hp=stworzenie.maxHp;
    exp=stworzenie.exp;
    lvl=stworzenie.lvl;
    nazwa=stworzenie.nazwa;
    return *this;
}

Stworzenie::~Stworzenie() {
    delete mocSpecjalna;
}

MocSpecjalna *Stworzenie::getMocSpecjalna() const {
    return mocSpecjalna;
}

string Stworzenie::toCSV() const {
    return nazwa + ";" + to_string(sila) + ";" + to_string(zrecznosc) + ";" + to_string(hp) + ";" + to_string(maxHp) + ";"
        + to_string(exp) + ";" + to_string(lvl) + ";" + to_string(typ) + ";" + mocSpecjalna->toCSV();
}

Stworzenie *Stworzenie::zaladuj(string daneStr) {
    vector<string> dane;
    size_t pos = 0;
    string token;
    string separator = ";";
    while ((pos = daneStr.find(separator)) != string::npos) {
        token = daneStr.substr(0, pos);
        dane.push_back(token);
        daneStr.erase(0, pos + separator.length());
    }
    dane.push_back(daneStr);
    //nazwa, sila, zrecznosc, hp, maxhp, exp lvl typ moc specjalna (ilosc uzyc, maxilosc uzyc, nazwa, wartosc, typ mocy specjalnej)
    MocSpecjalna* m = new MocSpecjalna(stoi(dane[10]), dane[11], stoi(dane[12]), (TYP_MOCY_SPECIALNEJ)stoi(dane[13]));
    Stworzenie* s = new Stworzenie(dane[1], stoi(dane[2]), stoi(dane[3]), stoi(dane[5]), (TYP)stoi(dane[8]), m);
    s->lvl = stoi(dane[7]);
    s->exp = stoi(dane[6]);
    return s;
}
