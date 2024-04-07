//
// Created by 48519 on 14.06.2022.
//

#include "Gracz.h"

Gracz::Gracz(int maxIloscStworzen) : maxIloscStworzen(maxIloscStworzen), wybrane(nullptr) {}

bool Gracz::dodajStworzenie(Stworzenie *stworzenie) {
    if(stworzenia.size() == maxIloscStworzen)
    {
        return false;
    }

    for(auto s : stworzenia)
    {
        if(*s == *stworzenie)
        {
            return false;
        }
    }

    stworzenia.push_back(new Stworzenie(*stworzenie));
    if(wybrane == nullptr)
    {
        wybrane = stworzenia.back();
    }
    return true;
}

Gracz::~Gracz() {
    usunStworzenia();
}

Gracz::Gracz(const Gracz &gracz) : maxIloscStworzen(gracz.maxIloscStworzen) {
    for(Stworzenie* s : gracz.stworzenia)
    {
        dodajStworzenie(s);
    }
}

Gracz &Gracz::operator=(const Gracz &gracz) {
    usunStworzenia();
    maxIloscStworzen = gracz.maxIloscStworzen;
    for(Stworzenie* s : gracz.stworzenia)
    {
        dodajStworzenie(s);
    }
    return *this;
}

void Gracz::usunStworzenia() {
    for(Stworzenie* s : stworzenia)
    {
        delete s;
    }
}

Wynik Gracz::wykonajAkcje(Stworzenie* wrog) {
    if(wybrane == nullptr)
    {
        return Wynik("Brak wybranego stworzenia");
    }
    if(wybrane->czyZemdlal())
    {
        wymiana();
        return Wynik("Dokonano wymiany");
    }

    auto decyzja = podejmijDecyzje();
    switch (decyzja) {
        case ATAK:
            return atakuj(wrog);
        case EWOLUCJA:
            if(!wybrane->czyMoznaEwoluowac())
            {
                return Wynik("Nie mozna wykonac ewolucji - za malo punkow exp!");
            }
            ewolucja();
            return Wynik("Wykonano ewolucje");
        case WYMIANA:
            wymiana();
            return Wynik("Dokonano wymiany");
    }

    return Wynik("Bledna decyzja");
}

ostream &operator<<(ostream &os, const Gracz &gracz) {
    for(auto s : gracz.stworzenia)
    {
        os << *s << "\n";
    }
    if(gracz.wybrane != nullptr)
    {
        os << "Aktualnie walczy: " << *gracz.wybrane << "\n";
    }
    return os;
}

Stworzenie *Gracz::getWybrane() const {
    return wybrane;
}

bool Gracz::posiadaZyweStworzenia() const {
    for(auto s : stworzenia)
    {
        if(!s->czyZemdlal())
        {
            return true;
        }
    }
    return false;
}

void Gracz::ocucStworzenia() {
    for(auto s : stworzenia)
    {
        s->ocuc();
    }
}

const vector<Stworzenie *> &Gracz::getStworzenia() const {
    return stworzenia;
}
