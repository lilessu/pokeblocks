#ifndef POKEMOVE_H
#define POKEMOVE_H

#include "utility.h"
#include "PokeType.h"

using namespace std;

struct PokeMove {
    std::string name;
    PokeType type;
    Category category;
    int power;
    int accuracy;
    int currentPp;
    int maxPp;
    bool hasSpecialEffect;
    std::string specialEffectString;
};

#endif   // POKEMOVE_H
