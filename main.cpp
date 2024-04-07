#include "Gra.h"

#include <iostream>
#include <string>
using std::cout;
using std::string;

///Typ komendy uzytej do uruchomienia gry
enum KOMENDA {
    POMOC, GRA, BLAD, ZALADUJ
};

const int ILOSC_RUND = 4;
const int BAZOWA_ILOSC_PRZECIWNIKOW = 4;

///Przetwarza z argumentow wywolania programu tryb dzialania programu
///@param argc ilosc argumentow
///@param argv tablica argumentow
///@return wczytana komenda dzialania
KOMENDA przetwarzaj(int argc, char** argv)
{
    if(argc < 2)
    {
        return KOMENDA::BLAD;
    }

    string param(argv[1]);
    if(param == "--help")
    {
        return KOMENDA::POMOC;
    }
    else if(param == "--play" && argc == 3)
    {
        return KOMENDA::GRA;
    }
    else if(param == "--load" && argc == 3)
    {
        return KOMENDA::ZALADUJ;
    }

    return KOMENDA::BLAD;
}

///Uruchamia gre z wybranym poziomem trudnosci
///@param poziom poziom trudnosci
void uruchomGre(POZIOM_TRUDNOSCI poziom)
{
    Gra* g = new Gra(poziom, ILOSC_RUND, BAZOWA_ILOSC_PRZECIWNIKOW);
    g->rozpocznij();
    delete g;
}

///Uruchamia gre na podstawie danych z pliku
///@param nazwaPliku nazwa pliku z zapisem stanu rozgrywki
void zaladujGre(string nazwaPliku)
{
    Gra* g = Gra::zaladujGre(nazwaPliku);
    g->rozpocznij();
    delete g;
}

int main(int argc, char** argv) {
    auto komenda = przetwarzaj(argc, argv);
    switch (komenda) {
        case KOMENDA::ZALADUJ:
            zaladujGre(argv[2]);
            break;
        case KOMENDA::GRA:
            uruchomGre((POZIOM_TRUDNOSCI)atoi(argv[2]));
            break;
        case KOMENDA::POMOC:
            cout << "--play [0/1/2] - uruchomienie gry" << endl;
            cout << "--help - pomoc" << endl;
            cout << "--load [nawa pliku] - zaladowanie zapisanej gry" << endl;
            break;
        case KOMENDA::BLAD:
            cout << "Niepoprawne parametry wywolania, uzyj --help aby uzyskac pomoc\n";
            break;
    }

}

