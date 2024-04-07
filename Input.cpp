//
// Created by 48519 on 15.06.2022.
//

#include "Input.h"

int Input::wczytajLiczbe(int start, int stop) {
    bool wczytano = false;
    int liczba = 0;

    while(!wczytano)
    {
        string line;
        getline(cin, line);
        try {
            liczba = stoi(line);
            if(liczba >= start && liczba <= stop)
            {
                wczytano = true;
            }
            else
            {
                cout << "Podana liczba nie miesci sie w przedziale: [" << start << ", " << stop << "]\n";
            }
        }
        catch (exception e)
        {
            cout << "Wprowadzona wartosc nie jest liczba calkowita\n";
        }
    }
    return liczba;
}
