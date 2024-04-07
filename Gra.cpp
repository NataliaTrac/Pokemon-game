//
// Created by 48519 on 17.06.2022.
//

#include "Gra.h"

bool Gra::walka(Gracz *g1, Gracz *g2) {
    const int ILOSC_KROPEK = 16;
    const int CZAS_ZATRZYMANIA_MS = 250;

    Gracz* gracze[] = {g1, g2};
    int index = 0;
    cout << "Rozpoczecie rozgrywki -------------------- " << endl;
    while(g1->posiadaZyweStworzenia() && g2->posiadaZyweStworzenia())
    {
        cout << "\n";
        cout << "Aktualnie gra gracz nr: " << (index + 1) << endl;
        cout << *gracze[index] <<endl;
        auto wynik = gracze[index]->wykonajAkcje(gracze[!index]->getWybrane());
        cout << wynik << endl;
        index = !index;
        cout << "-----------------------" << endl;
        for(int i = 0; i < ILOSC_KROPEK; i++)
        {
            cout << ".";
            sleep_for(milliseconds(CZAS_ZATRZYMANIA_MS));
        }
        cout << "\n";
    }
    return g1->posiadaZyweStworzenia();
}

void Gra::rozpocznij() {
    stworzGracza();
    if(aktualnaRunda >= iloscRund)
    {
        aktualnaRunda = 0;
    }
    auto wynikRundy = STAN_RUNDY::WYGRANA;
    int iloscPrzeciwnikow = bazowaIloscPrzeciwnikow;
    for( ; aktualnaRunda < iloscRund && wynikRundy == STAN_RUNDY::WYGRANA; aktualnaRunda++)
    {
        cout << "Runda nr " << (aktualnaRunda + 1) << endl;
        wynikRundy = rozpocznijRudne(iloscPrzeciwnikow);
        iloscPrzeciwnikow += iloscDodatkowychPrzeciwnikow;
    }

    switch(wynikRundy)
    {
        case PRZEGRANA:
            cout << "Przegrana!" << endl;
            break;
        case WYGRANA:
            cout << "Wygrana" << endl;
            break;
        case WYJSCIE:
            zapisz();
            cout << "Wyjscie!" << endl;
            break;
    }
    usunGracza();
}

Gra::Gra(POZIOM_TRUDNOSCI poziomTrudnosci, int iloscRund, int bazowaIloscPrzeciwnikow)
    : poziomTrudnosci(poziomTrudnosci), iloscRund(iloscRund), bazowaIloscPrzeciwnikow(bazowaIloscPrzeciwnikow),
      repozytoriumStworzen(poziomTrudnosci), aktualnaRunda(0), aktualnyPrzeciwnik(0),
    gracz(nullptr) {
    switch(poziomTrudnosci)
    {
        case LATWY:
            iloscDodatkowychPrzeciwnikow = 0;
            break;
        case SREDNI:
        case TRUDNY:
            iloscDodatkowychPrzeciwnikow = 1;
            break;
    }
}

STAN_RUNDY Gra::rozpocznijRudne(int iloscPrzeciwnikow) {
    if(aktualnyPrzeciwnik >= iloscPrzeciwnikow)
    {
        aktualnyPrzeciwnik = 0;
    }
    for(; aktualnyPrzeciwnik < iloscPrzeciwnikow; aktualnyPrzeciwnik++)
    {
        cout << "Aktualnie walczysz z przeciwnikiem nr " << (aktualnyPrzeciwnik+1) << endl;
        Komputer komputer(KOMPUTER_ILOSC_STWORZEN, poziomTrudnosci);
        komputer.wybierzStworzenia(repozytoriumStworzen);
        bool sukces = walka(gracz, &komputer);
        if(!sukces)
        {
            return STAN_RUNDY::PRZEGRANA;
        }
        gracz->ocucStworzenia();

        cout << "Czy chcesz kontynuowac? (tak/nie). W przypadku wyjscia gra zostanie zapisana.\n";
        string odp;
        getline(cin, odp);
        if(odp != "tak")
        {
            return STAN_RUNDY::WYJSCIE;
        }
    }
    return STAN_RUNDY::WYGRANA;
}

void Gra::stworzGracza() {
    if(gracz == nullptr)
    {
        gracz = new Czlowiek(GRACZ_ILOSC_STWORZEN);
        gracz->wybierzStworzenia(repozytoriumStworzen);
    }
}

void Gra::usunGracza() {
    if(gracz != nullptr)
    {
        delete gracz;
        gracz = nullptr;
    }
}

void Gra::zapisz() {
    ofstream plik(ZAPIS_PLIK);
    if(!plik.is_open())
    {
        cout << "Nie udalo sie wykonac zapisu\n";
        return;
    }

    plik << poziomTrudnosci << " " << aktualnaRunda << " " << aktualnyPrzeciwnik << " " << iloscRund << " "
    << bazowaIloscPrzeciwnikow << "\n";

    auto graczStworzenia = gracz->getStworzenia();
    plik << graczStworzenia.size() << "\n";
    for(auto s : graczStworzenia)
    {
        int wybrany = (s == gracz->getWybrane());
        plik << wybrany << ";" << s->toCSV() << "\n";
    }
    plik.close();
}

Gra *Gra::zaladujGre(string nazwaPliku) {
    ifstream plik(nazwaPliku);
    if(!plik.is_open())
    {
        cout << "Nie mozna zaladowac gry, niepoprawny plik" << endl;
        exit(-1);
    }

    int poziom, aktualnaRunda, aktualnyPrzeciwnik, iloscRund, bazowaIloscPrzeciwnikow;
    plik >> poziom >> aktualnaRunda >> aktualnyPrzeciwnik >> iloscRund >> bazowaIloscPrzeciwnikow;
    Gra* g = new Gra((POZIOM_TRUDNOSCI)poziom, iloscRund, bazowaIloscPrzeciwnikow);
    g->aktualnyPrzeciwnik = aktualnyPrzeciwnik;
    g->aktualnaRunda = aktualnaRunda;

    int iloscStworzen;
    plik >> iloscStworzen;
    g->gracz = new Czlowiek(iloscStworzen);

    string line;
    getline(plik ,line);

    for(int i = 0; i < iloscStworzen; i++)
    {
        getline(plik, line);
        Stworzenie* s = Stworzenie::zaladuj(line);
        g->gracz->dodajStworzenie(s);
    }
    return g;
}
