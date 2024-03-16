#ifndef BATTLE_H
#define BATTLE_H

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

#include "PokeMove.h"
#include "PokeType.h"
#include "StatsData.h"
#include "utility.h"
#include "Ability.h"
#include "Pokemon.h"

class Battle {
    public:

    struct TurnChoice {
        char team;
        Pokemon* movingPokemon;
        PokeMove* chosenMove;
        Pokemon* chosenTarget;
    };

    Battle( std::vector<Pokemon*>& paramTeamA,  std::vector<Pokemon*>& paramTeamB);

    void doBattle();



    private:
    std::vector<Pokemon*>& teamA;
    std::vector<Pokemon*>& teamB;
    int turnNum;
    std::vector<TurnChoice> turnChoiceVec;


    void printBattleStartMsg();

    void doTurn();

    void getChoice();

    void getAttackChoice(bool& param);
    void getItemChoice(bool& param);
    void getSwitchChoice(bool& param);
    void getRunChoice(bool& param);

    void getPokemonAttackChoice(Pokemon* currPokemon, bool& param);
    void getPokemonAttackTarget(Pokemon* currPokemon, int chosenMove, bool& param);
    

};

#endif