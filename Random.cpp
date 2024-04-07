//
// Created by 48519 on 14.06.2022.
//

#include "Random.h"

Random Random::instance;

Random::Random()
    : rng(dev()),
        dist(RANDOM_MIN, RANDOM_MAX){

}

Random &Random::getInstance() {
    return instance;
}

int Random::randInt100() {
    return dist(rng);
}

int Random::randInt(int start, int stop) {
    std::uniform_int_distribution<std::mt19937::result_type> dist(start, stop);
    return dist(rng);
}
