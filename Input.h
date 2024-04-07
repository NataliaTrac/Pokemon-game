//
// Created by 48519 on 15.06.2022.
//

#ifndef PROJEKT_INPUT_H
#define PROJEKT_INPUT_H

#include <string>
#include <iostream>
using std::stoi;
using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::exception;

class Input {
public:
    ///Wczytuje liczbe calkowita od uzytkownika z konsoli z zakresu [start, stop]
    ///@param start zakres dolny wczytywanej liczby
    ///@param stop zakres gorny wczytywanej liczby
    ///@return wczytana liczba calkowita
    static int wczytajLiczbe(int start, int stop);
};


#endif //PROJEKT_INPUT_H
