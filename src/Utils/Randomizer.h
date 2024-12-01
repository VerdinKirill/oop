#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <random>
#include <chrono>


class Randomizer {
private:
    std::mt19937 gen;
    std::uniform_int_distribution<int> distr;
    // std::uniform_int_distribution<int> distr_bool;
    bool getRandomBool();
public:
    Randomizer(int start, int end);
    int getRandomInt();
    // void placeShipRandomly(GameField& field, Ship* ship);
};

#endif