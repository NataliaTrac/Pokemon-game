//
// Created by 48519 on 14.06.2022.
//

#ifndef PROJEKT_RANDOM_H
#define PROJEKT_RANDOM_H

#include <random>

const int RANDOM_MIN = 0;
const int RANDOM_MAX = 100;

class Random {
private:
    static Random instance;
    std::random_device dev;
    std::mt19937 rng;
    std::uniform_int_distribution<std::mt19937::result_type> dist;
    Random();
public:
    ///Zwraca referencje do instancji klasy Random
    ///@return obiekt klasy Random
    static Random& getInstance();

    ///Losuje liczbe z przedzialu [0, 100]
    ///@return liczba z przedzialu [0, 100]
    int randInt100();

    ///Losuje liczbe z przedzialu [start, end]
    ///@param start poczatek przedzialu losowania
    ///@param stop koniec przedzialu losowania
    ///@return wylosowana liczba z przedzialu [start, stop]
    int randInt(int start, int end);
};


#endif //PROJEKT_RANDOM_H
