#ifndef STATSDATA_H
#define STATSDATA_H

#include "Ability.h"
#include "PokeMove.h"
#include "PokeType.h"
#include "utility.h"

struct StatsData {
    std::string name;
    int currHp;

    int hp;   // max hp, calculated based on baseHp, ivHp, evHp, level
    int attack;
    int defense;
    int spAttack;
    int spDefense;
    int speed;

    int baseHp;
    int baseAttack;
    int baseDefense;
    int baseSpAttack;
    int baseSpDefense;
    int baseSpeed;

    int ivHp;
    int ivAttack;
    int ivDefense;
    int ivSpAttack;
    int ivSpDefense;
    int ivSpeed;

    int evHp;
    int evAttack;
    int evDefense;
    int evSpAttack;
    int evSpDefense;
    int evSpeed;

    int level;
    Nature nature;
    Gender gender;
    vector<PokeType> types;
    vector<PokeMove> moves;
    Ability ability;
    int catchRate;
};

#endif   //  STATSDATA_H
