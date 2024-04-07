//
// Created by 48519 on 14.06.2022.
//

#include "RepozytoriumStworzen.h"
#include "MocSpecjalna.h"

RepozytoriumStworzen::RepozytoriumStworzen(POZIOM_TRUDNOSCI poziomTrudnosci) {
    string nazwy[] = {"Squirtle", "Charizard", "Magneton", "Seel", "Blastoise", "Vulpix", "Growlithe", "Aaron","Ferroseed","Sandshrew","Geodude","Diglett","Jynx","Darumaka","Vanillish"};
    int sila[] = {14, 17, 13, 19, 18, 15, 14, 17,14,13,12,17,14,13,12};
    int zrecznosc[] = {5, 3, 9, 5, 8, 3, 4, 8,6,9,8,7,5,6,5};
    int maxHp[] = {80, 100, 95, 100, 80, 95, 80, 100,95,95,100,90,100,95,100};
    TYP typ[] = {WODA, OGIEN, STAL, WODA, WODA, OGIEN, OGIEN, STAL,STAL,ZIEMIA,ZIEMIA,ZIEMIA,LOD,LOD,LOD};
    int iloscUzyc[] = {3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3};
    string nazwyMocy[] = {"Wodny atak", "Ognisty atak", "Stalowa tarcza", "Wodna tarcza", "Wodny atak", "Ognisty atak", "Ognista tarcza", "Stalowy atak","Stalowa tarcza","Ziemny atak","Ziemny atak","Ziemna tarcza","Lodowy atak","Lodowa tarcza","Lodowy atak"};
    int wartosc[] = {3, 3, 3, 3, 3, 3, 3, 3,3,3,3,3,3,3,3};
    TYP_MOCY_SPECIALNEJ typMocy[] = {MOC_ATAK, MOC_ATAK, MOC_OBRONA, MOC_OBRONA, MOC_ATAK, MOC_ATAK, MOC_OBRONA, MOC_ATAK,MOC_OBRONA,MOC_ATAK,MOC_ATAK,MOC_ATAK,MOC_ATAK,MOC_OBRONA,MOC_ATAK};

    int n = sizeof(sila)/sizeof(int);

    for(int i = 0; i < n; i++)
    {
        switch(poziomTrudnosci)
        {
            case SREDNI:
                sila[i] = sila[i] + sila[i] * WSP_SILY_POZIOM_SREDNI;
                zrecznosc[i] = zrecznosc[i] + zrecznosc[i] * WSP_ZRECZNOSCI_POZIOM_SREDNI;
                maxHp[i] = maxHp[i] + maxHp[i] * WSP_HP_POZIOM_SREDNI;
                wartosc[i] = wartosc[i] * WSP_WARTOSC_MOCY_POZIOM_SREDNI;
                iloscUzyc[i] += DODATKOWA_ILOSC_UZYC_POZIOM_SREDNI;
                break;
            case TRUDNY:
                sila[i] = sila[i] + sila[i] * WSP_SILY_POZIOM_TRUDNY;
                zrecznosc[i] = zrecznosc[i] + zrecznosc[i] * WSP_ZRECZNOSCI_POZIOM_TRUDNY;
                maxHp[i] = maxHp[i] + maxHp[i] * WSP_HP_POZIOM_TRUDNY;
                wartosc[i] = wartosc[i] * WSP_WARTOSC_MOCY_POZIM_TRUDNY;
                iloscUzyc[i] += DODATKOWA_ILOSC_UZYC_POZIOM_TRUDNY;
                break;
        }
    }

    for(int i = 0; i < n; i++)
    {
        stworzenia.push_back(new Stworzenie(nazwy[i], sila[i], zrecznosc[i], maxHp[i], typ[i], new MocSpecjalna(iloscUzyc[i], nazwyMocy[i], wartosc[i], typMocy[i])));
    }
}

RepozytoriumStworzen::RepozytoriumStworzen(const RepozytoriumStworzen &repozytorium) {
    for(Stworzenie* s : repozytorium.stworzenia)
    {
        stworzenia.push_back(new Stworzenie(*s));
    }
}

RepozytoriumStworzen &RepozytoriumStworzen::operator=(const RepozytoriumStworzen &repozytorium) {
    usunStworzenia();
    for(Stworzenie* s : repozytorium.stworzenia)
    {
        stworzenia.push_back(new Stworzenie(*s));
    }
    return *this;
}

RepozytoriumStworzen::~RepozytoriumStworzen() {
    usunStworzenia();
}

void RepozytoriumStworzen::usunStworzenia() {
    for(Stworzenie* s : stworzenia)
    {
        delete s;
    }
}

Stworzenie *RepozytoriumStworzen::getStworzenie(int index) const {
    if(index < 0 || index >= stworzenia.size())
    {
        return nullptr;
    }
    return stworzenia[index];
}

ostream &operator<<(ostream &os, const RepozytoriumStworzen &repozytorium) {
    int i = 1;
    for(Stworzenie* s : repozytorium.stworzenia)
    {
        os << i++ << ". " << *s << "\n";
    }
    return os;
}

int RepozytoriumStworzen::iloscStworzen() const {
    return stworzenia.size();
}
