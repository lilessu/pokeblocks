#ifndef POKETYPE_H
#define POKETYPE_H

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

// holds poketype enum classes
// holds category enum class


enum class PokeType {
    Normal,
    Fire,
    Fighting,
    Water,
    Flying,
    Grass,
    Poison,
    Electric,
    Ground,
    Psychic,
    Rock,
    Ice,
    Bug,
    Dragon,
    Ghost,
    Dark,
    Steel,
    Fairy,
};

class PokeTypeUtility {
    public:

    const static int numTypes = 18;

    static double getDmgMultiplierHelper(const PokeType& attackType, const PokeType& defenseType);

    static double getDmgMultiplier(const PokeType& attackType, const std::vector<PokeType>& defenseTypeList);

    private:
    static double typeEffectivenessChart[PokeTypeUtility::numTypes][PokeTypeUtility::numTypes];
};

enum PokeTypeNum {
    Normal = 0,
    Fire = 1,
    Water = 2,
    Electric = 3,
    Grass = 4,
    Ice = 5,
    Fighting = 6,
    Poison = 7,
    Ground = 8,
    Flying = 9,
    Psychic = 10,
    Bug = 11,
    Rock = 12,
    Ghost = 13,
    Dragon = 14,
    Dark = 15,
    Steel = 16,
    Fairy = 17
};


#endif   //  POKETYPE_H
