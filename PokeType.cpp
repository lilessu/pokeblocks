#include <algorithm>
#include <cmath>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <limits>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#include "PokeType.h"


double PokeTypeUtility::typeEffectivenessChart[PokeTypeUtility::numTypes][PokeTypeUtility::numTypes] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0.5, 0, 1, 1, 0.5, 1}, //normal
    {1, .5, .5, 1, 2, 2, 1, 1, 1, 1, 1, 2, .5, 1, .5, 1, 2, 1}, //fire
    {1, 2, .5, 1, .5, 1, 1, 1, 2, 1, 1, 1, 2, 1, .5, 1, 1, 1},  //water
    {1, 1, 2, .5, .5, 1, 1, 1, 0, 2, 1, 1, 1, 1, .5, 1, 1, 1},   //electric
    {1, .5, 2, 1, .5, 1, 1, .5, 2, .5, 1, .5, 2, 1, .5, 1, .5, 1},  //GRASS
    {1, .5, .5, 1, 2, .5, 1, 1, 2, 2, 1, 1, 1, 1, 2, 1, .5, 1}, //ICE
    {2, 1, 1, 1, 1, 2, 1, .5, 1, .5, .5, .5, 2, 0, 1, 2, 2, .5}, //fight
    {1, 1, 1, 1, 2, 1, 1, .5, .5, 1, 1, 1, .5, .5, 1, 1, 0, 2}, //poisin
    {1, 2, 1, 2, .5, 1, 1, 2, 1, 0, 1, .5, 2, 1, 1, 1, 2, 1},
    {1, 1, 1, .5, 2, 1, 2, 1, 1, 1, 1, 2, .5, 1, 1, 1, 2, 1},   //flying
    {1, 1, 1, 1, 1, 1, 2, 2, 1, 1, .5, 1, 1, 1, 1, 0, .5, 1},   //psychic
    {1, .5, 1, 1, 2, 1, .5, .5, 1, .5, 2, 1, 1, .5, 1, 2, .5, .5}, //bug
    {1, 2, 1, 1, 1, 2, .5, 1, .5, 2, 1, 2, 1, 1, 1, 1, .5, 1},  //rock
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, .5, 1, 1},    //ghost
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, .5, 0},    //dragon
    {1, 1, 1, 1, 1, 1, .5, 1, 1, 1, 2, 1, 1, 2, 1, .5, 1, .5},  //dark
    {1, .5, .5, .5, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, .5, 2}, //steel
    {1, .5, 1, 1, 1, 1, 2, .5, 1, 1, 1, 1, 1, 1, 2, 2, .5, 1}   //fairy

};

// Used to calculate a single attackType vs. defenseType multplier.
double PokeTypeUtility::getDmgMultiplierHelper(const PokeType& attackType, const PokeType& defenseType) {
    double retVal;
    retVal = PokeTypeUtility::typeEffectivenessChart[static_cast<PokeTypeNum>(attackType)][static_cast<PokeTypeNum>(defenseType)];
    return retVal;
}

// Calculates total attack vs. defense multiplier.
double PokeTypeUtility::getDmgMultiplier(const PokeType& attackType, const std::vector<PokeType>& defenseTypeList) {
    double retVal = 1;
    for (size_t i = 0; i < defenseTypeList.size(); i++) {
        retVal *= getDmgMultiplierHelper(attackType, defenseTypeList[i]);
    }
    return retVal;
}

