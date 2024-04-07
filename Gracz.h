//
// Created by 48519 on 14.06.2022.
//

#ifndef PROJEKT_GRACZ_H
#define PROJEKT_GRACZ_H

#include "Stworzenie.h"
#include "RepozytoriumStworzen.h"
#include <vector>
using std::vector;
using std::ostream;

const int ILOSC_AKCJI = 3;

enum AKCJA {
    ATAK, EWOLUCJA, WYMIANA
};

class Gracz {
protected:
    vector<Stworzenie*> stworzenia;
    Stworzenie* wybrane;
    int maxIloscStworzen;

public:
    ///Konstruktor klasy Gracz
    ///@param maxIloscStworzen maksymalna ilosc posiadanych przez gracza stworzen
    Gracz(int maxIloscStworzen);

    ///Konstruktor kopiujacy klasy Gracz
    ///@param gracz obiekt z ktorego beda kopiowane dane
    Gracz(const Gracz& gracz);

    ///Operator przypisania dla klasy Gracz
    ///@param gracz obiekt z ktorego beda kopiowane dane
    ///@return obiekt klasy gracz do ktorego skopiowano dane
    Gracz& operator=(const Gracz& gracz);

    ///Usuwa wszystkie stworzenia gracza
    void usunStworzenia();

    ///Dodaje stworzenie graczowi, jesli gracz nie ma stworzen do pierwsze dodane stworzenie stanie sie jego wybranym w grze
    ///W przypadku istnienia stworzenia operacja zakonczy sie niepowodzeniem
    ///@param stworzenie dodawane stworzenie
    ///@return prawda jesli stworzenie zostalo pomyslnie dodane
    bool dodajStworzenie(Stworzenie* stworzenie);

    ///Okresla sposob w jaki gracz podejmuje decyzje
    ///@return decyzja gracza (atak, ewolucja, wymiana)
    virtual AKCJA podejmijDecyzje() = 0;

    ///Okresla sposob ataku na stworzenie
    ///@param wrog stworzenie ktore zostanie zaatakowane
    ///@return wynik ataku w formie obiektu wiadomosci
    virtual Wynik atakuj(Stworzenie* wrog) = 0;

    ///Okresla sposob wymiany stworzenia
    virtual void wymiana() = 0;

    ///Okresla sposob ewolucji
    virtual void ewolucja() = 0;

    ///Okresla sposob wyboru stworzen z puli dostepnych
    ///@param repozytorium dostepna pula wszystkich stworzen
    virtual void wybierzStworzenia(const RepozytoriumStworzen& repozytorium) = 0;

    ///Pobiera od gracza decyzje odnosnie rozgrywki i ja realizuje
    ///@param wrog stworzenie przeciwnika ktore moze byc zaatakowane
    ///@return obiekt wiadomosci o wyniku akcji
    Wynik wykonajAkcje(Stworzenie* wrog);


    Stworzenie *getWybrane() const;
    const vector<Stworzenie *> &getStworzenia() const;

    ~Gracz();

    ///Informuje czy gracz posiada przynajmniej jedno zywe stworzenie
    ///@return prawda jesli gracz posiada przynamniej jedno zywe stworzenie
    bool posiadaZyweStworzenia() const;

    ///Przywraca dla wszystkich stworzen gracza parametry zycia, uzyc mocy specjalnej itp
    void ocucStworzenia();

    friend ostream& operator<<(ostream& os, const Gracz& gracz);
};

ostream& operator<<(ostream& os, const Gracz& gracz);

#endif //PROJEKT_GRACZ_H
